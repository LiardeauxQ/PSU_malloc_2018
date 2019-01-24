/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

const int DATA_BLOCK_SIZE = align(sizeof(data_info_t));

static void *check_free_block(data_info_t **data, size_t size)
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
		new = (void *)tmp + DATA_BLOCK_SIZE + size;
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

static int create_elem(data_info_t **elem, size_t size)
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

static int append(data_info_t **data, size_t size)
{
    data_info_t *tmp = *data;

	if (tmp == NULL)
		return (create_elem(data, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (create_elem(&tmp->next, size))
		return (1);
	tmp->next->prev = tmp;
	return (0);
}

void *get_head(void *ptr, char mode)
{
    static data_info_t *head = NULL;

    if (mode == 1 && head == NULL) {
        head = ptr;
        return (head);
    }
    return (head);
}

void *malloc(size_t size)
{
    data_info_t *data = (data_info_t*)get_head(NULL, 0);
    void *p = NULL;

    size = align(size);
    p = check_free_block(&data, size);
    if (p == NULL) {
        if (append(&data, size))
            return (NULL);
        if ((p = sbrk(size)) == (void*)-1)
            return (NULL);
    }
    get_head(data, 1);
    show_block_info(p - DATA_BLOCK_SIZE);
    return (p);
}
