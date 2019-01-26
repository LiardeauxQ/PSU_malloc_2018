/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** calloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t new_size = compute_pagesize(size * nmemb);

	return (memset(malloc(new_size), 0, new_size));
}
