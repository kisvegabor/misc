/**
 * @file fat32.h
 * Functions to give an API to a Fat32 storage device which is compatible 
 * with the fs_int module. 
 */

#ifndef FAT32_H
#define FAT32_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_FAT32 != 0

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
void fat32_init(void);
bool fat32_ready(void);

fs_res_t fat32_open (void * file_p, const char * path, fs_mode_t mode);
fs_res_t fat32_close (void * file_p);
fs_res_t fat32_remove(const char * path);
fs_res_t fat32_read (void * file_p, void * buf, uint32_t btr, uint32_t * br);
fs_res_t fat32_write (void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
fs_res_t fat32_seek (void * file_p, uint32_t pos);
fs_res_t fat32_tell (void * file_p, uint32_t * pos_p);
fs_res_t fat32_trunc (void * file_p);
fs_res_t fat32_size (void * file_p, uint32_t * size_p);

fs_res_t fat32_readdir_init(void * rddir_p, const char * path);
fs_res_t fat32_readdir(void * rddir_p, char * fn);
fs_res_t fat32_readdir_close(void * rddir_p);
/**********************
 *      MACROS
 **********************/

#endif

#endif