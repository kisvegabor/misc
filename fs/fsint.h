/**
 * @file fsint.h
 * 
 */

#ifndef FSINT_H
#define FSINT_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_FSINT != 0

#include <stdint.h>
#include <stdbool.h>
#include "../mem/dyn_mem.h"

/*********************
 *      DEFINES
 *********************/
#define FSINT_MAX_FN_LENGTH  64

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    FS_RES_OK = 0,
    FS_RES_HW_ERR,      /*Low level hardwer error*/
    FS_RES_FS_ERR,      /*Error in the file system structure */
    FS_RES_NOT_EX,      /*Driver, file or direcory is not exists*/
    FS_RES_FULL,        /*Disk full*/
    FS_RES_LOCKED,      /*The file is already opened*/
    FS_RES_DENIED,      /*Access denied. Check 'fs_open' modes and write protect*/
    FS_BUSY,            /*The filesystem now can't handle it, try later*/
    FS_RES_TOUT,        /*Process timeouted*/
    FS_RES_NOT_IMP,     /*Requested function is not implemented*/
    FS_RES_OUT_OF_MEM,  /*Not enough memory for an internal opretion*/
    FS_RES_INV_PARAM,   /*Invalid parameter among arguments*/
    FS_RES_UNKNOWN,     /*Other unknown error*/
}fs_res_t;

struct __fs_drv_struct;
        
typedef struct
{
    void * file_d;
    struct __fs_drv_struct* drv;
}fs_file_t;


typedef struct
{
    void * rddir_d;
    struct __fs_drv_struct * drv;
}fs_readdir_t;

typedef enum
{
    FS_MODE_WR = 0x01,
    FS_MODE_RD = 0x02,
}fs_mode_t;

typedef struct __fs_drv_struct
{
    char letter;
    uint16_t file_size;
    uint16_t rddir_size;
    bool (*ready) (void);
    
    fs_res_t (*open) (void * file_p, const char * path, fs_mode_t mode);
    fs_res_t (*close) (void * file_p);
    fs_res_t (*remove) (const char * fn);
    fs_res_t (*read) (void * file_p, void * buf, uint32_t btr, uint32_t * br);
    fs_res_t (*write) (void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
    fs_res_t (*seek) (void * file_p, uint32_t pos);
    fs_res_t (*tell) (void * file_p, uint32_t * pos_p);
    fs_res_t (*trunc) (void * file_p);
    fs_res_t (*size) (void * file_p, uint32_t * size_p);
    
    fs_res_t (*rddir_init) (void * rddir_p, const char * path);
    fs_res_t (*rddir) (void * rddir_p, char * fn);
    fs_res_t (*rddir_close) (void * rddir_p);
}fs_drv_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void fs_init(void);
void fs_add_drv(fs_drv_t * drv_p);

fs_res_t fs_open (fs_file_t * file_p, const char * path, fs_mode_t mode);
fs_res_t fs_close (fs_file_t * file_p);
fs_res_t fs_remove (const char * fn);
fs_res_t fs_read (fs_file_t * file_p, void * buf, uint32_t btr, uint32_t * br);
fs_res_t fs_write (fs_file_t * file_p, const void * buf, uint32_t btw, uint32_t * bw);
fs_res_t fs_seek (fs_file_t * file_p, uint32_t pos);
fs_res_t fs_tell (fs_file_t * file_p, uint32_t * pos);

fs_res_t fs_readdir_init(fs_readdir_t * rddir_p, const char * path);
fs_res_t fs_readdir (fs_readdir_t * rddir_p, char * fn);
fs_res_t fs_readdir_close (fs_readdir_t * rddir_p);

char *  fs_get_letters(char * buf);
const char * fs_get_ext(const char * fn);
char * fs_up(char * fn);

/**********************
 *      MACROS
 **********************/

#endif

#endif
