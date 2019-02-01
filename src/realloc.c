/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

void *realloc(void *ptr, size_t size)
{
    data_info_t *old_data = NULL;
    data_info_t *new_data = NULL;
    unsigned char *new_ptr = NULL;
    unsigned char *tmp_ptr = ptr;

    if (size == 0 || (new_ptr = malloc(size)) == NULL) {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (new_ptr);
    old_data = ptr - get_block_size(); 
    new_data = (void*)new_ptr - get_block_size();
    for (size_t i = 0 ; i < old_data->size_blk
            && i < new_data->size_blk ; i++)
        *(new_ptr + i) = *(tmp_ptr + i);
    free(ptr);
    return (new_ptr);
}
