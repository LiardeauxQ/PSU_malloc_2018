/*
** EPITECH PROJECT, 2018
** handle_size.c
** File description:
** handle size
*/

#include "malloc.h"
#include "show_alloc_mem.h"

size_t get_block_size(void)
{
    return (compute_pagesize(sizeof(data_info_t)));
}

size_t compute_pagesize(size_t size)
{
    size_t new_size = size;
    size_t page_size = getpagesize();

    new_size += page_size - (new_size % page_size);
    return (new_size);
}
