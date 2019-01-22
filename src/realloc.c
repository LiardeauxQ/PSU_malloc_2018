/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** realloc.c
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	void *new_p = NULL;
	data_info_t *info_ptr = NULL;
	unsigned char *stock_new_p = NULL;
	unsigned char *stock_ptr = NULL;

	if (size == 0) {
		free(ptr);
		return (NULL);
	}
	if ((new_p = malloc(size)) == NULL) {
		free(ptr);
		return (NULL);
	}
	stock_new_p = new_p;
	stock_ptr = ptr;
	if ((ptr == NULL) || (ptr < stock_start_heap() || ptr > sbrk(0)))
		return (new_p);
	info_ptr = ptr - DATA_BLOCK_SIZE;
	for (size_t i = 0 ; i < info_ptr->size_blk ; i++)
		*(stock_new_p + i) = *(stock_ptr + i);
	free(ptr);
	return (new_p);
}