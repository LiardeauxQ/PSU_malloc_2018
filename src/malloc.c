/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"

const int DATA_BLOCK_SIZE = align(sizeof(data_info_t));

int create_elem(data_info_t **elem, size_t size)
{
	(*elem) = sbrk(DATA_BLOCK_SIZE);
	if ((*elem) == (void*)-1)
		return (1);
	(*elem)->empty = 0;
	(*elem)->size_blk = size;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	return (0);
}

int append(data_info_t **data, size_t size)
{
	data_info_t *tmp = *data;

	if (*data == NULL) {
		if (create_elem(data, size))
			return (1);
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (create_elem(&tmp->next, size))
		return (1);
	tmp->next->prev = tmp;
	return (0);
}

int insert(data_info_t **data, size_t size)
{
	data_info_t *new = NULL;

	if (create_elem(&new, size))
		return (1);
	new->next = (*data)->next;
	(*data)->next = new;
	(*data)->prev = (*data);
	if ((*data)->next != NULL)
		(*data)->next->prev = new;
	return (0);
}

void *check_free_block(data_info_t **data, size_t size)
{
	data_info_t *tmp = *data;
	data_info_t *new = NULL;

	while (tmp != NULL) {
		if (size <= tmp->size_blk && tmp->empty == 1)
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	if (align(tmp->size_blk - size) >= ((size_t)DATA_BLOCK_SIZE + 8)) {
		new = (void *)tmp + align(DATA_BLOCK_SIZE + size);
		new->empty = 1;
		new->size_blk = align(tmp->size_blk - DATA_BLOCK_SIZE - size);
		new->next = tmp->next;
		new->prev = tmp;
		if (new->next != NULL)
			new->next->prev = new;
		tmp->next = new;
	}
	tmp->empty = 0;
	tmp->size_blk = size;
	return ((void *)tmp + DATA_BLOCK_SIZE);
}

void *stock_start_heap(void)
{
	static void *start_heap = NULL;

	if (!start_heap)
		start_heap = sbrk(0);
	if (start_heap == (void*)-1)
		return (NULL);
	return (start_heap);
}

void *malloc(size_t size)
{
	static data_info_t *data = NULL;
	void *p = NULL;

	if (size == 0)
		return (NULL);
	stock_start_heap();
	size = align(size);
	p = check_free_block(&data, size);
	if (p == NULL) {
		if (append(&data, size))
			return (NULL);
		if ((p = sbrk(size)) == (void*)-1)
			return (NULL);
	}
	return (p);
}
