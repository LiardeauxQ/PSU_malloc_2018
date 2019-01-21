/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** Prototypes
*/

#ifndef __MALLOC_H__
# define __MALLOC_H__

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

extern void *base_bloc;

typedef struct s_bloc
{
  struct s_bloc	*next;
  struct s_bloc	*prev;
  bool isFree;
  size_t getSize;
  void *data;
  char just_for_align_header;
} t_bloc;

# define __HEADER_SIZE__ sizeof(struct s_bloc) //Recommencer tests pour vérifier utilité et corriger si nécessaire
# define __ALIGN_ADDR__(size, power) (((size - 1) / power + 1) * power) //Plus opti power avec variable ou =16

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *realloc_func(t_bloc *bloc, void *ptr, size_t size);
void create_rest_bloc(t_bloc *bloc, size_t size, int pagesize);
t_bloc *extend_heap(t_bloc *last_bloc, size_t size);
int split_bloc(t_bloc *this_bloc, size_t size);
t_bloc *fusion_free_bloc(t_bloc *bloc);
t_bloc *find_free_bloc(t_bloc *bloc, size_t size);
void *get_bloc(void *ptr);
void copy_data(t_bloc *bloc, t_bloc *new_bloc);
t_bloc *copy_bloc(t_bloc *bloc, size_t size);
void my_putchar(char c);
int my_strlen(char const *str);
void my_putstr(char const *str);
void my_put_nbr(size_t nb);
void my_put_hex(size_t nb);
void show_alloc_mem();
void *trylock_thread();
void *unlock_thread();

#endif
