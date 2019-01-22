/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

void show_alloc_mem()
{
	data_info_t *heap = stock_start_heap();

    printf("break: %p\n", heap);
    while (heap) {
        printf("%p - %p : %ld bytes\n", heap + DATA_BLOCK_SIZE, heap->next, heap->size_blk);
        heap = heap->next;
    }
}
