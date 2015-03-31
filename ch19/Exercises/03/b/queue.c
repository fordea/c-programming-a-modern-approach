#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE void queue_underflow(void);

PRIVATE struct contents {
    Item item;
    struct contents *next;
} *head = NULL, *tail = NULL;

PRIVATE int num_items = 0;

PUBLIC void enqueue(Item i)
{
    struct contents *new_item;
    if ((new_item = malloc(sizeof (struct contents))) == NULL)
    {
        printf("Error, malloc failed in enqueue.\n");
        exit(EXIT_FAILURE);
    }

    new_item->item = i;
    new_item->next = NULL;
    num_items++;

    if (head == NULL)
    {
        head = tail = new_item;
    }
    else
    {
        tail->next = new_item;
        tail = new_item;
    }
}

PUBLIC Item dequeue(void)
{
    if (!is_empty())
    {
        struct contents *temp = head;
        Item i = head->item;
        head = head->next;
        free(temp);
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
        return head->item;
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
        return tail->item;
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
