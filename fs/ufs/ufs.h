/**
 * @file ufs.h
 * Implementation of RAM file system which do NOT support directories.
 * The API is compatible with the fs_int module.
 */

#ifndef UFS_H
#define UFS_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_UFS != 0

#include "../fsint.h"
#include "misc/mem/dyn_mem.h"
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Descripton of a file entry */
typedef struct
{
    char * fn_d;
    void * data_d;
    uint32_t size;  /*Data length in bytes*/
    uint16_t oc;    /*Open Count*/
    uint8_t const_data :1;
}ufs_ent_t;

/*File descriptor, used to handle opening an entry more times simultaneously 
 Contains unique informations about the specific opening*/
typedef struct
{
    ufs_ent_t* ent;
    uint32_t rwp;   /*Read Write Pointer*/
    uint8_t ar :1;  /*1: Access for read is enabled */
    uint8_t aw :1;  /*1: Access for write is enabled */
}ufs_file_t;

typedef struct
{
    ufs_ent_t * last_ent;
}ufs_read_dir_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void ufs_init(void);
bool ufs_ready(void);

fs_res_t ufs_open (void * file_p, const char * path, fs_mode_t mode);
fs_res_t ufs_create_const(const char * fn, const void * const_p, uint32_t len);
fs_res_t ufs_close (void * file_p);
fs_res_t ufs_remove(const char * fn);
fs_res_t ufs_read (void * file_p, void * buf, uint32_t btr, uint32_t * br);
fs_res_t ufs_write (void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
fs_res_t ufs_set_const(void * file_p, const void * const_p, uint32_t len);
fs_res_t ufs_seek (void * file_p, uint32_t pos);
fs_res_t ufs_tell (void * file_p, uint32_t * pos_p);
fs_res_t ufs_trunc (void * file_p);
fs_res_t ufs_size (void * file_p, uint32_t * size_p);

fs_res_t ufs_readdir_init(void * rddir_p, const char * path);
fs_res_t ufs_readdir(void * rddir_p, char * fn);
fs_res_t ufs_readdir_close(void * rddir_p);

/**********************
 *      MACROS
 **********************/

#endif

#endif
