/*
** EPITECH PROJECT, 2018
** Malloc.c
** File description:
** Allocate memory
*/

#include "malloc.h"

void *base_bloc = NULL;

void *malloc(size_t size)
{
  t_bloc *this_bloc;

  trylock_thread();
  if ((long int)size < 0)
	  return (unlock_thread());
  size = __ALIGN_ADDR__(size, 16);
  if ((this_bloc = find_free_bloc(base_bloc, size)) != NULL)
    {
      if (split_bloc(this_bloc, size) == 1)
	{
	  if ((this_bloc = extend_heap(base_bloc, size)) == NULL)
	    return (unlock_thread());
	}
    }
  else
    {
      if ((this_bloc = extend_heap(base_bloc, size)) == NULL)
	return (unlock_thread());
    }
  if (base_bloc == NULL)
    base_bloc = this_bloc;
  unlock_thread();
  return (this_bloc->data);
}

/*
int main()
{
	char *test1 = malloc(100);
	memset(test1, 0, 100);
	free(test1);
	test1 = malloc(30);
	return 0;
}
*/
