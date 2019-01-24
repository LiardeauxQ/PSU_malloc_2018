/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc.c
*/

#include "show_alloc_mem.h"

void my_putnbr(size_t nbr)
{
    char c = 48;

    c += (nbr % 10);
    nbr = nbr / 10;
    if (nbr > 0)
        my_putnbr(nbr);
    write(2, &c, 1);
}

void my_putstr(char *str)
{
    write(2, str, strlen(str));
}

void show_block_info(data_info_t *data)
{
    my_putnbr((size_t)data + DATA_BLOCK_SIZE);
    my_putstr(" - ");
    my_putnbr((size_t)data->next);
    my_putstr(" allocate ");
    my_putnbr(data->size_blk);
    my_putstr(" bytes and is Free ");
    my_putnbr(data->empty);
    my_putstr("\n");
}

void show_alloc_mem()
{
	data_info_t *head = get_head(NULL, 0);

    my_putstr("break: ");
    my_putnbr((size_t)head);
    my_putstr(" struct size ");
    my_putnbr(DATA_BLOCK_SIZE);
    my_putstr("\n");
    while (head) {
        show_block_info(head); 
        head = head->next;
    }
}

