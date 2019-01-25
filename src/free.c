/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"

void *find_data_info_addr(void *ptr)
{
	void *start_heap = stock_start_heap();

	if (start_heap) {
		if (ptr > start_heap && ptr < sbrk(0))
			return (ptr - DATA_BLOCK_SIZE);
	}
	return (NULL);
}

void merge_data_block(data_info_t **data)
{
	data_info_t *start = *data;
	data_info_t *end = *data;

	while (start->prev != NULL && start->prev->empty == 1)
		start = start->prev;
	while (end != NULL && end->empty == 1)
		end = end->next;
	if (start == end)
		return;
	if (end != NULL)
		start->size_blk = ((size_t)(end) - ((size_t)(start)
                    + DATA_BLOCK_SIZE));
	else
		start->size_blk = ((size_t)(sbrk(0)) - ((size_t)(start)
                    + DATA_BLOCK_SIZE));
	start->empty = 1;
	start->next = end;
	if (end != NULL)
		end->prev = start;
}

void free(void *ptr)
{
	data_info_t *data = NULL;

	if (ptr == NULL)
		return;
	if (!(data = find_data_info_addr(ptr)))
		return;
	data->empty = 1;
    //	merge_data_block(&data);
}

