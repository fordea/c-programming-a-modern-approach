#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC /* empty */
#define PRIVATE static
#define QUEUE_MAX 100

PRIVATE void queue_underflow(void);
PRIVATE void queue_overflow(void);

PRIVATE Item contents[QUEUE_MAX];
PRIVATE int idx_first_item = 0;
PRIVATE int idx_new_item = 0;
PRIVATE int num_items = 0;

PUBLIC void enqueue(Item i)
{
    if (num_items < QUEUE_MAX)
    {
        contents[idx_new_item] = i;
        idx_new_item = ((idx_new_item + 1) == QUEUE_MAX) ? 0 : idx_new_item + 1;
        num_items++;
    }
    else
    {
        queue_overflow();
    }
}

PUBLIC Item dequeue(void)
{
    if (!is_empty())
    {
        Item i = contents[idx_first_item];
        idx_first_item++;
        num_items--;
        return i;
    }
    else
    {
        queue_underflow();
    }
}

PUBLIC Item get_first(void)
{
    if (!is_empty())
    {
        return contents[idx_first_item];
    }
    else
    {
        queue_underflow();
    }
}

PUBLIC Item get_last(void)
{
    if (!is_empty())
    {
        if (idx_new_item == 0)
            return contents[QUEUE_MAX - 1];
        else
            return contents[idx_new_item - 1];
    }
    else
    {
        queue_underflow();
    }
}

PUBLIC int items_in_queue(void)
{
    return num_items;
}

PUBLIC bool is_empty(void)
{
    return num_items == 0;
}

PRIVATE void queue_underflow(void)
{
    printf("Error, queue is empty.\n");
    exit(EXIT_FAILURE);
}

PRIVATE void queue_overflow(void)
{
    printf("Error, queue is full.\n");
    exit(EXIT_FAILURE);
}
