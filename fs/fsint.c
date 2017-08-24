/**
 * @file fs_int.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/

#include "misc_conf.h"
#if USE_FSINT != 0

#include "fsint.h"
#include <string.h>
#include "../mem/linked_list.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static const char * fs_get_real_path(const char * path);
static fs_drv_t* fs_get_drv(char letter);


/**********************
 *  STATIC VARIABLES
 **********************/
static ll_dsc_t drv_ll;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the File system interface
 */
void fs_init(void)
{
    ll_init(&drv_ll, sizeof(fs_drv_t));
}



/**
 * Open a file
 * @param file_p pointer to a fs_file_t variable
 * @param path path to the file beginning with the driver letter (e.g. S:/folder/file.txt)
 * @param mode read: FS_MODE_RD, write: FS_MODE_WR, both: FS_MODE_RD | FS_MODE_WR
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_open (fs_file_t * file_p, const char * path, fs_mode_t mode)
{
    file_p->drv = NULL;
    file_p->file_d = NULL;
    
    if(path == NULL) return FS_RES_INV_PARAM;

    char letter = path[0];
    
    file_p->drv = fs_get_drv(letter);
    
    if(file_p->drv == NULL) {
        file_p->file_d = NULL;
        return FS_RES_NOT_EX;
    }
    
    if(file_p->drv->ready != NULL) {
        if(file_p->drv->ready() == false) {
            file_p->drv = NULL;
            file_p->file_d = NULL;
            return FS_RES_HW_ERR;
        }
    }
    
    file_p->file_d = dm_alloc(file_p->drv->file_size);
    if(file_p->file_d == NULL) {   
        file_p->drv = NULL;
        return FS_RES_OUT_OF_MEM;  /* Out of memory */
    }        
    
    if(file_p->drv->open == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    const char * real_path = fs_get_real_path(path);
    fs_res_t res = file_p->drv->open(file_p->file_d, real_path, mode);
    
    return res;
}

/**
 * Close an already opened file
 * @param file_p pointer to a fs_file_t variable
 * @return  FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_close (fs_file_t * file_p)
{
    if(file_p->drv == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv->close == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    fs_res_t res = file_p->drv->close(file_p->file_d);
    
    dm_free(file_p->file_d);   /*Clean up*/
    file_p->file_d = NULL;
    file_p->drv = NULL;
    file_p->file_d = NULL;
    
    return res;
}

/**
 * Delete a file
 * @param path path of the file to delete
 * @return  FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_remove (const char * path)
{
    if(path == NULL) return FS_RES_INV_PARAM;
    fs_drv_t * drv = NULL;

    char letter = path[0];

    drv = fs_get_drv(letter);
    if(drv == NULL) return FS_RES_NOT_EX;
    if(drv->ready != NULL) {
       if(drv->ready() == false) return FS_RES_HW_ERR;
    }

   if(drv->remove == NULL) return FS_RES_NOT_IMP;

   const char * real_path = fs_get_real_path(path);
   fs_res_t res = drv->remove(real_path);

   return res;
}

/**
 * Read from a file
 * @param file_p pointer to a fs_file_t variable
 * @param buf pointer to a buffer where the read bytes are stored
 * @param btr Bytes To Read
 * @param br the number of real read bytes (Bytes Read). NULL if unused.
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_read (fs_file_t * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    if(br != NULL) *br = 0;
    if(file_p->drv == NULL || file_p->drv == NULL) return FS_RES_INV_PARAM;
    if(file_p->drv->read == NULL) return FS_RES_NOT_IMP;
    
    uint32_t br_tmp = 0;
    fs_res_t res = file_p->drv->read(file_p->file_d, buf, btr, &br_tmp);
    if(br != NULL) *br = br_tmp;
    
    return res;
}

/**
 * Write into a file
 * @param file_p pointer to a fs_file_t variable
 * @param buf pointer to a buffer with the bytes to write
 * @param btr Bytes To Write
 * @param br the number of real written bytes (Bytes Written). NULL if unused.
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_write (fs_file_t * file_p, const void * buf, uint32_t btw, uint32_t * bw)
{
    if(bw != NULL) *bw = 0;
    
    if(file_p->drv == NULL || file_p->drv == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv->write == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    uint32_t bw_tmp = 0;
    fs_res_t res = file_p->drv->write(file_p->file_d, buf, btw, &bw_tmp);
    if(bw != NULL)  *bw = bw_tmp;
    
    return res;
}

/**
 * Set the position of the 'cursor' (read write pointer) in a file
 * @param file_p pointer to a fs_file_t variable
 * @param pos the new position expressed in bytes index (0: start of file)
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_seek (fs_file_t * file_p, uint32_t pos)
{
    if(file_p->drv == NULL || file_p->drv == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv->seek == NULL) {
        return FS_RES_NOT_IMP;
    }
        
    fs_res_t res = file_p->drv->seek(file_p->file_d, pos);
    
    return res;
}

/**
 * Give the position of the read write pointer
 * @param file_p pointer to a fs_file_t variable
 * @param pos_p pointer to store the position of the read write pointer
 * @return FS_RES_OK or any error from 'fs_res_t'
 */
fs_res_t fs_tell (fs_file_t * file_p, uint32_t  * pos)
{
    if(file_p->drv == NULL || file_p->drv == NULL) {
        pos = 0;
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv->tell == NULL) {
        pos = 0;
        return FS_RES_NOT_IMP;
    }
        
    fs_res_t res = file_p->drv->tell(file_p->file_d, pos);
    
    return res;
}

/**
 * Give the size of a file bytes
 * @param file_p pointer to a fs_file_t variable
 * @param size pointer to a variable to store the size
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_size (fs_file_t * file_p, uint32_t * size)
{
    if(file_p->drv == NULL || file_p->drv == NULL) {
        return FS_RES_INV_PARAM;
    }

    if(file_p->drv->size == NULL) return FS_RES_NOT_IMP;


    if(size == NULL) return FS_RES_INV_PARAM;

    fs_res_t res = file_p->drv->size(file_p->file_d, size);

    return res;
}

/**
 * Initialize a 'fs_read_dir_t' variable for directory reading
 * @param rddir_p pointer to a 'fs_read_dir_t' variable
 * @param path path to a directory
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_readdir_init(fs_readdir_t * rddir_p, const char * path)
{
    if(path == NULL) return FS_RES_INV_PARAM;

    char letter = path[0];
    
    rddir_p->drv = fs_get_drv(letter);
    
    if(rddir_p->drv == NULL) {
        rddir_p->rddir_d = NULL;
        return FS_RES_NOT_EX;
    }
    
    rddir_p->rddir_d = dm_alloc(rddir_p->drv->file_size);
    if(rddir_p->rddir_d == NULL) {   
        rddir_p->rddir_d = NULL;
        return FS_RES_OUT_OF_MEM;  /* Out of memory */
    }        
    
    if(rddir_p->drv->rddir_init == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    const char * real_path = fs_get_real_path(path);
    fs_res_t res = rddir_p->drv->rddir_init(rddir_p->rddir_d, real_path);
    
    return res;
}

/**
 * Read the next filename form a directory. 
 * The name of the directories will begin with '/'
 * @param rddir_p pointer to an initialized 'fs_read_dir_t' variable
 * @param fn pointer to a buffer to store the filename
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_readdir (fs_readdir_t * rddir_p, char * fn)
{
    if(rddir_p->drv == NULL || rddir_p->rddir_d == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(rddir_p->drv->rddir == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    fs_res_t res = rddir_p->drv->rddir(rddir_p->rddir_d, fn);
    
    return res;   
}

/**
 * Close the directory reading
 * @param rddir_p pointer to an initialized 'fs_read_dir_t' variable
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_readdir_close (fs_readdir_t * rddir_p)
{
    if(rddir_p->drv == NULL || rddir_p->rddir_d == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    fs_res_t res;
           
    if(rddir_p->drv->rddir_close == NULL) {
        res =  FS_RES_NOT_IMP;
    } else {
        res = rddir_p->drv->rddir_close(rddir_p->rddir_d);
    }
    
    dm_free(rddir_p->rddir_d);   /*Clean up*/
    rddir_p->rddir_d = NULL;
    rddir_p->drv = NULL;
    rddir_p->rddir_d = NULL;
    
    return res;
}

/**
 * Get the free and total size of a driver in kB
 * @param letter the driver letter
 * @param total_p pointer to store the total size [kB]
 * @param free_p pointer to store the free size [kB]
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_free (char letter, uint32_t * total_p, uint32_t * free_p)
{
    fs_drv_t * drv = fs_get_drv(letter);

    if(drv == NULL) {
        return FS_RES_INV_PARAM;
    }

    fs_res_t res;

    if(drv->free == NULL) {
        res =  FS_RES_NOT_IMP;
    } else {
        uint32_t total_tmp = 0;
        uint32_t free_tmp = 0;
        res = drv->free(&total_tmp, &free_tmp);

        if(total_p != NULL) *total_p = total_tmp;
        if(free_p != NULL) *free_p = free_tmp;
    }

    return res;
}

/**
 * Add a new drive
 * @param drv_p pointer to an fs_drv_t structure which is inited with the 
 * corresponding function pointer. The data will be copied so the variable can be local.
 */
void fs_add_drv(fs_drv_t * drv_p)
{
   /*Save the new driver*/
   fs_drv_t* new_drv;
   new_drv =  ll_ins_head(&drv_ll); 
   dm_assert(new_drv);
   memcpy(new_drv, drv_p, sizeof(fs_drv_t));
   
}

/**
 * Fill a buffer with the letters of existing drivers  
 * @param buf buffer to store the letters ('\0' added after the last letter)
 * @return the buffer
 */
char *  fs_get_letters(char * buf)
{
   fs_drv_t* drv;
   uint8_t i = 0;
   
   LL_READ(drv_ll, drv) {
       buf[i] = drv->letter;
       i++;
   }
   
   buf[i] = '\0';
   
   return buf;
}


/**
 * Return with the extension of the filename
 * @param fn string with a filename
 * @return pointer to the beginning extension or empty string if no extension
 */
const char * fs_get_ext(const char * fn)
{
    uint16_t i;
    for(i = strlen(fn); i > 0; i --) {
        if(fn[i] == '.') {
            return &fn[i + 1];
        } else if(fn[i] == '/' || fn[i] == '\\') {
            return "";  /*No extension if a '\' or '/' found*/
        }
    }
    
    return ""; /*Empty string if no '.' in the file name. */
}

/**
 * Step up one level
 * @param path pointer to a file name
 * @return the truncated file name
 */
char * fs_up(char * path)
{
    uint16_t len = strlen(path);
    if(len == 0) return path;

    len --; /*Go before the trailing '\0'*/

    /*Ignore trailing '/' or '\'*/
    while(path[len] == '/' || path[len] == '\\') {
        path[len] = '\0';
        if(len > 0) len --;
        else return path;
    }

    uint16_t i;
    for(i = len; i > 0; i --) {
        if(path[i] == '/' || path[i] == '\\') break;
    }

    path[i] = '\0';

    return path;
}

/**
 * Get the last element of a path (e.g. U:/folder/file -> file)
 * @param path a character sting with the path to search in
 * @return pointer to the beginning of the last element in the path
 */
const char * fs_get_last(const char * path)
{
    uint16_t len = strlen(path);
    if(len == 0) return path;

    len --; /*Go before the trailing '\0'*/

    /*Ignore trailing '/' or '\'*/
    while(path[len] == '/' || path[len] == '\\') {
        if(len > 0) len --;
        else return path;
    }

    uint16_t i;
    for(i = len; i > 0; i --) {
        if(path[i] == '/' || path[i] == '\\') break;
    }

    /*No '/' or '\' in the path so return with path itself*/
    if(i == 0) return path;

    return &path[i + 1];
}
/**********************
 *   STATIC FUNCTIONS
 **********************/

 /**
  * Leave the driver letters and / or \ letters from beginning of the path
  * @param path path string (E.g. S:/folder/file.txt)
  * @return pointer to the beginning of the real path (E.g. folder/file.txt)
  */
static const char * fs_get_real_path(const char * path) 
{
    /* Example path: "S:/folder/file.txt" 
     * Leave the letter and the : / \ characters*/
    
    path ++; /*Ignore the driver letter*/
    
    while(*path != '\0') {    
        if(*path == ':' || *path == '\\' || *path == '/'){
            path ++;
        }
        else {
            break;
        }
    }
    
    return path;
}

/**
 * Give a pointer to a driver from its letter
 * @param letter the driver letter
 * @return pointer to a driver or NULL if not found
 */
static fs_drv_t* fs_get_drv(char letter)
{
    fs_drv_t* drv;
    
    LL_READ(drv_ll, drv) {
        if(drv->letter == letter) {
            return drv;
        }
    }
    
    return NULL;
}

#endif
