/**
 * @file linked_list.c
 * Handle linked lists. The nodes are dynamically allocated by the dyn_mem module.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"

#if USE_LINKED_LIST != 0
#include "dyn_mem.h"
#include <stdint.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/*Dummy type to make handling easier*/
typedef uint8_t ll_node_t;

/*Description of a linked list*/
typedef struct
{
    uint32_t n_size;
    ll_node_t* head;
    ll_node_t* tail;
}ll_dsc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void ll_init(ll_dsc_t * ll_dsc, uint32_t n_size);
void * ll_ins_head(ll_dsc_t * ll);
void * ll_ins_tail(ll_dsc_t * ll);
void * ll_ins_after(ll_dsc_t * ll, void * n_act);
void * ll_ins_before(ll_dsc_t * ll, void * n_act);
void ll_rem(ll_dsc_t * ll, void * n_act);
void ll_clear(ll_dsc_t * ll_p);
void ll_chg_list(ll_dsc_t * ll_ori_p, ll_dsc_t * ll_new_p, void * node);
void * ll_get_head(ll_dsc_t * ll);
void * ll_get_tail(ll_dsc_t * ll);
void * ll_get_next(ll_dsc_t * ll, void * n_act);
void * ll_get_prev(ll_dsc_t * ll, void * n_act);
void ll_swap(ll_dsc_t * ll_p, void * n1_p, void * n2_p);


/**********************
 *      MACROS
 **********************/

#define LL_READ(list, i) for(i = ll_get_head(&list); i != NULL; i = ll_get_next(&list, i))

#define LL_READ_BACK(list, i) for(i = ll_get_tail(&list); i != NULL; i = ll_get_prev(&list, i))

#endif /*USE_LINKED_LIST != 0*/

#endif
