/**
 * @file linuxfs.c
 * Functions to give an API to the standard
 * file operation functions to be compatible
 */


#ifndef LINUXFS_H
#define LINUXFS_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_LINUXFS != 0

#include "../fsint.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void linuxfs_init(void);
bool linuxfs_ready(void);

fs_res_t linuxfs_open (void * file_p, const char * path, fs_mode_t mode);
fs_res_t linuxfs_close (void * file_p);
fs_res_t linuxfs_remove(const char * path);
fs_res_t linuxfs_read (void * file_p, void * buf, uint32_t btr, uint32_t * br);
fs_res_t linuxfs_write (void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
fs_res_t linuxfs_seek (void * file_p, uint32_t pos);
fs_res_t linuxfs_tell (void * file_p, uint32_t * pos_p);
fs_res_t linuxfs_size (void * file_p, uint32_t * size_p);

fs_res_t linuxfs_readdir_init(void * rddir_p, const char * path);
fs_res_t linuxfs_readdir(void * rddir_p, char * fn);
fs_res_t linuxfs_readdir_close(void * rddir_p);
/**********************
 *      MACROS
 **********************/

#endif

#endif
