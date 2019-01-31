/*
** EPITECH PROJECT, 2018
** thread_safety.c
** File description:
** thread safety
*/

#include "malloc.h"

pthread_mutex_t *get_mutex(void)
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    return (&mutex);
}
void *trylock_thread(void)
{
    if (pthread_mutex_lock(get_mutex()) != 0)
        exit(0);
    return (NULL);
}

void *unlock_thread(void)
{
    if (pthread_mutex_unlock(get_mutex()) != 0)
        exit(0);
    return (NULL);
}
