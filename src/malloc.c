/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc.c
*/

#include "malloc.h"
#include "show_alloc_mem.h"

const size_t DATA_BLOCK_SIZE = sizeof(data_info_t);

static int create_elem(data_info_t **elem, size_t size)
{
    (*elem) = sbrk(get_block_size());
    if ((*elem) == (void*)-1)
        return (1);
    (*elem)->empty = 0;
    (*elem)->size_blk = size;
    (*elem)->next = NULL;
    (*elem)->prev = NULL;
    return (0);
}

static int append(data_info_t **data, size_t size)
{
    data_info_t *tmp = *data;

    if (tmp == NULL)
        return (create_elem(data, size));
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (create_elem(&tmp->next, size))
        return (1);
    tmp->next->prev = tmp;
    return (0);
}

void *get_head(void *ptr, char mode)
{
    static data_info_t *head = NULL;

    if (mode == 1 && head == NULL) {
        head = ptr;
        return (head);
    }
    return (head);
}

void *malloc(size_t size)
{
    data_info_t *data = (data_info_t*)get_head(NULL, 0);
    void *p = NULL;

    trylock_thread();
    size = compute_pagesize(size);
    p = check_free_block(&data, size);
    if (p == NULL) {
        if (append(&data, size)) {
            unlock_thread();
            return (NULL);
        }
        if ((p = sbrk(size)) == (void*)-1) {
            unlock_thread();
            return (NULL);
        }
    }
    get_head(data, 1);
    unlock_thread();
    return (p);
}
