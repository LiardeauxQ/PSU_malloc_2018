/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"

void print_alloc_memory()
{
	data_info_t *heap = stock_start_heap();

	printf("NEXT\n");
	while (heap->next != NULL) {
		printf("%p - %p : %ld bytes empty %d\n", heap, heap->next, heap->size_blk, heap->empty);
		heap = heap->next;
	}
	printf("%p - %p : %ld bytes empty %d\n", heap, heap->next, heap->size_blk, heap->empty);
	printf("PREV\n");
	while (heap != NULL) {
		printf("%p - %p : %ld bytes empty %d\n", heap, heap->next, heap->size_blk, heap->empty);
		heap = heap->prev;	
	}
}