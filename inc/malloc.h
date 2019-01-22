/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.h
*/

#ifndef MALLOC_H_
	#define MALLOC_H_
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//#define align(size) (((size -1) / 16 + 1) * 16)
#define align(x) (((((x) - 1) >> 3) << 3) + 8)

extern const int DATA_BLOCK_SIZE;

typedef struct data_info_s {
	int empty;
	size_t size_blk;
	struct data_info_s *next;
	struct data_info_s *prev;
} data_info_t;

/* malloc.c */

void *malloc(size_t size);
void *stock_start_heap(void);
int insert(data_info_t **data, size_t size);
int append(data_info_t **data, size_t size);
int create_elem(data_info_t **elem, size_t size);

/* realloc.c */

void *realloc(void *ptr, size_t size);

/* calloc.c */

//void *calloc(size_t nmemb, size_t size);

/* free.c */

void free(void *ptr);

#endif /* MALLOC_H_ */
