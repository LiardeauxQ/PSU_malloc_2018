/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** main.c
*/

#include "malloc.h"

typedef struct test_s {
	int number;
	double dub;
	char *string;
} test_t;

void print_array(test_t **array)
{
	for (int i = 0 ; array[i] != 0x0 ; i++) {
		for (int j = 0; array[i][j].number != -1 ; j++) {
			printf("num %d dub %f string %s %p\n", array[i][j].number, array[i][j].dub, array[i][j].string, array[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int size = 5;
	char **array = mmalloc((size + 1) * sizeof(char*));

	for (int i = 0 ; i < size ; i++) {
		array[i] = mmalloc(size * size);
	}
	print_alloc_memory();
	mfree(array[0]);
	mfree(array[1]);
	array[0] = mmalloc(size + 1);
	array[1] = mmalloc(size + 1);
	print_alloc_memory();
	return (0);
}