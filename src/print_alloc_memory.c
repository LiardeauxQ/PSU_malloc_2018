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
	data_info_t *head = stock_start_heap();

    printf("break: %p struct size %d\n", head, DATA_BLOCK_SIZE);
    while (head) {
        printf("%p - %p : %ld bytes isFree %d\n", head +
                DATA_BLOCK_SIZE, head->next, head->size_blk, head->empty);
        head = head->next;
    }
}

