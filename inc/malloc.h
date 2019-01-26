/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.h
*/

#ifndef MALLOC_H_
#	define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define align(x) (((((x) - 1) >> 3) << 3) + 8)

extern const size_t DATA_BLOCK_SIZE;

typedef struct data_info_s {
    char empty;
    size_t size_blk;
    struct data_info_s *next;
    struct data_info_s *prev;
} data_info_t;

/* malloc.c */

void *malloc(size_t size);
void *get_head(void *ptr, char mode);

/* check_free_block.c */

void *check_free_block(data_info_t **data, size_t size);

/* realloc.c */

void *realloc(void *ptr, size_t size);

/* calloc.c */

void *calloc(size_t nmemb, size_t size);

/* free.c */

void free(void *ptr);

/* check_ptr.c */

int check_ptr(void *ptr);

#endif /* MALLOC_H_ */
