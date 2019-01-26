/*
** EPITECH PROJECT, 2018
** thread_safety.c
** File description:
** thread safety
*/

#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *trylock_thread()
{
    if (pthread_mutex_lock(&mutex) != 0)
        exit(0);
    return (NULL);
}

void *unlock_thread()
{
    if (pthread_mutex_unlock(&mutex) != 0)
        exit(0);
    return (NULL);
}
