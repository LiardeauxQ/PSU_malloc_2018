/*
** EPITECH PROJECT, 2018
** check_ptr.c
** File description:
** check ptr
*/

#include "malloc.h"

int check_ptr(void *ptr)
{
    data_info_t *head = get_head(NULL, 0);

    if ((size_t)ptr > ((size_t)head + DATA_BLOCK_SIZE) && ptr < sbrk(0))
        return (0);
    return (1);
}
