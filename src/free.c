/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

static data_info_t *find_data_info_addr(void *ptr)
{
    if (!check_ptr(ptr))
        return (ptr - get_block_size());
    return (NULL);
}

void free(void *ptr)
{
    data_info_t *data = NULL;

    if (ptr == NULL)
        return;
    if (!(data = find_data_info_addr(ptr)))
        return;
    data->empty = 1;
}
