/*
** EPITECH PROJECT, 2018
** show_alloc_mem.h
** File description:
** show alloc mem header
*/

#ifndef SHOW_ALLOC_MEM_H_
    #define SHOW_ALLOC_MEM_H_

#include <string.h>
#include <unistd.h>
#include "malloc.h"

void my_putnbr(size_t nbr);
void my_putstr(char *str);
void show_block_info(data_info_t *data);
void show_alloc_mem(void);

#endif
