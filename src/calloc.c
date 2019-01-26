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
	return (memset(malloc(nmemb * size), 0, align(nmemb * size)));
}
