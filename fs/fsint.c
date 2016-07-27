/**
 * @file fs_int.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include <string.h>

#include "misc_conf.h"
#if USE_FSINT != 0

#include "fsint.h"
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
    if(path == NULL) return FS_RES_INV_PARAM;

    char letter = path[0];
    
    file_p->drv_dp = fs_get_drv(letter);
    
    if(file_p->drv_dp == NULL) {
        file_p->file_dp = NULL;
        return FS_RES_NOT_EX;
    }
    
    if(file_p->drv_dp->ready != NULL) {
        if(file_p->drv_dp->ready() == false) {
            file_p->drv_dp = NULL;
            file_p->file_dp = NULL;
            return FS_RES_HW_ERR;
        }
    }
    
    file_p->file_dp = dm_alloc(file_p->drv_dp->file_size);
    if(file_p->file_dp == NULL) {   
        file_p->drv_dp = NULL;
        return FS_RES_OUT_OF_MEM;  /* Out of memory */
    }        
    
    if(file_p->drv_dp->open == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    const char * real_path = fs_get_real_path(path);
    fs_res_t res = file_p->drv_dp->open(file_p->file_dp, real_path, mode);
    
    return res;
}

/**
 * Close an already opened file
 * @param file_p pointer to a fs_file_t variable
 * @return  FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_close (fs_file_t * file_p)
{
    if(file_p->drv_dp == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv_dp->close == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    fs_res_t res = file_p->drv_dp->close(file_p->file_dp);
    
    dm_free(file_p->file_dp);   /*Clean up*/
    file_p->drv_dp = NULL;
    file_p->file_dp = NULL;
    
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
    if(file_p->drv_dp == NULL || file_p->drv_dp == NULL) return FS_RES_INV_PARAM;
    if(file_p->drv_dp->read == NULL) return FS_RES_NOT_IMP;
    
    uint32_t br_tmp = 0;
    fs_res_t res = file_p->drv_dp->read(file_p->file_dp, buf, btr, &br_tmp);
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
    
    if(file_p->drv_dp == NULL || file_p->drv_dp == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv_dp->write == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    uint32_t bw_tmp = 0;
    fs_res_t res = file_p->drv_dp->write(file_p->file_dp, buf, btw, &bw_tmp);
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
    if(file_p->drv_dp == NULL || file_p->drv_dp == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv_dp->seek == NULL) {
        return FS_RES_NOT_IMP;
    }
        
    fs_res_t res = file_p->drv_dp->seek(file_p->file_dp, pos);
    
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
    if(file_p->drv_dp == NULL || file_p->drv_dp == NULL) {
        pos = 0;
        return FS_RES_INV_PARAM;
    }
    
    if(file_p->drv_dp->tell == NULL) {
        pos = 0;
        return FS_RES_NOT_IMP;
    }
        
    fs_res_t res = file_p->drv_dp->tell(file_p->file_dp, pos);
    
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
    
    rddir_p->drv_dp = fs_get_drv(letter);
    
    if(rddir_p->drv_dp == NULL) {
        rddir_p->rddir_dp = NULL;
        return FS_RES_NOT_EX;
    }
    
    rddir_p->rddir_dp = dm_alloc(rddir_p->drv_dp->file_size);
    if(rddir_p->rddir_dp == NULL) {   
        rddir_p->rddir_dp = NULL;
        return FS_RES_OUT_OF_MEM;  /* Out of memory */
    }        
    
    if(rddir_p->drv_dp->rddir_init == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    const char * real_path = fs_get_real_path(path);
    fs_res_t res = rddir_p->drv_dp->rddir_init(rddir_p->rddir_dp, real_path);
    
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
    if(rddir_p->drv_dp == NULL || rddir_p->rddir_dp == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    if(rddir_p->drv_dp->rddir == NULL) {
        return FS_RES_NOT_IMP;
    }
    
    fs_res_t res = rddir_p->drv_dp->rddir(rddir_p->rddir_dp, fn);
    
    return res;   
}

/**
 * Close the directory reading
 * @param rddir_p pointer to an initialized 'fs_read_dir_t' variable
 * @return FS_RES_OK or any error from fs_res_t enum
 */
fs_res_t fs_readdir_close (fs_readdir_t * rddir_p)
{
    if(rddir_p->drv_dp == NULL || rddir_p->rddir_dp == NULL) {
        return FS_RES_INV_PARAM;
    }
    
    fs_res_t res;
           
    if(rddir_p->drv_dp->rddir_close == NULL) {
        res =  FS_RES_NOT_IMP;
    } else {
        res = rddir_p->drv_dp->rddir_close(rddir_p->rddir_dp);
    }
    
    dm_free(rddir_p->rddir_dp);   /*Clean up*/
    rddir_p->drv_dp = NULL;
    rddir_p->rddir_dp = NULL;
    
    return res;
}

/**
 * Add a new drive
 * @param drv_p pointer to an fs_drv_t structure which is inited with the 
 * corresponding function pointer
 */
void fs_add_drv(fs_drv_t * drv_p)
{
   /*Save the new driver*/
   fs_drv_t* new_drv_dp;
   new_drv_dp =  ll_ins_head(&drv_ll); 
   dm_assert(new_drv_dp);
   memcpy(new_drv_dp, drv_p, sizeof(fs_drv_t));
   
}

/**
 * Fill a buffer with the letters of existing drivers  
 * @param buf buffer to store the letters ('\0' added after the last letter)
 * @return the buffer
 */
char *  fs_get_letters(char * buf)
{
   fs_drv_t* drv_dp;
   uint8_t i = 0;
   
   LL_READ(drv_ll, drv_dp) {
       buf[i] = drv_dp->letter;
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
    fs_drv_t* drv_dp;
    
    LL_READ(drv_ll, drv_dp) {
        if(drv_dp->letter == letter) {
            return drv_dp;
        }
    }
    
    return NULL;
}

#endif
