/*
 * Copyright (c), mr-library Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-08     MacRsh       first version
 */

#ifndef _MR_SERVE_H_
#define _MR_SERVE_H_

#include <mrdef.h>

#define mr_hw_interrupt_enable() \
do{                              \
}while(0)

#define mr_hw_interrupt_disable()\
do{                              \
}while(0)

#define mr_container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

#define mr_array_get_length(array)   sizeof(array)/sizeof(array[0])

MR_INLINE void mr_list_init(mr_list_t list)
{
	list->next = list;
	list->prev = list;
}

MR_INLINE void mr_list_insert_after(mr_list_t list, mr_list_t node)
{
	list->next->prev = node;
	node->next = list->next;

	list->next = node;
	node->prev = list;
}

MR_INLINE void mr_list_remove(mr_list_t node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;

	node->next = node->prev = node;
}

#endif
