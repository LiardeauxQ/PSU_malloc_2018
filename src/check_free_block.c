/*
** EPITECH PROJECT, 2018
** check_free_block.c
** File description:
** check free block function
*/

#include "malloc.h"

inline static void *find_best_block(data_info_t *data, size_t size)
{
    data_info_t *tmp = data;

    while (tmp != NULL) {
        if (size <= tmp->size_blk && tmp->empty == 1)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void *check_free_block(data_info_t **data, size_t size)
{
    data_info_t *tmp = find_best_block(*data, size);
    data_info_t *new = NULL;

    if (tmp == NULL)
        return (NULL);
    if (align(tmp->size_blk - size) >= (get_block_size() + 8)) {
        new = (void*)tmp + get_block_size() + size;
        new->empty = 1;
        new->size_blk = align(tmp->size_blk - get_block_size() - size);
        new->next = tmp->next;
        new->prev = tmp;
        if (new->next != NULL)
            new->next->prev = new;
        tmp->next = new;
    }
    tmp->empty = 0;
    tmp->size_blk = size;
    return ((void*)tmp + get_block_size());
}
