/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** realloc.c
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    data_info_t *data = NULL;
    unsigned char *new_ptr = NULL;
    unsigned char *tmp_ptr = ptr;

    //if (check_ptr(ptr))
    //    return (NULL);
    if (size == 0 || (new_ptr = malloc(size)) == NULL) {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (new_ptr);
    data = ptr - DATA_BLOCK_SIZE;
    for (size_t i = 0 ; i < data->size_blk ; i++)
        *(new_ptr + i) = *(tmp_ptr + i);
    free(ptr);
    return (new_ptr);
}
