#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE void queue_underflow(void);

PRIVATE struct node {
    Item item;
    struct node *next;
} *head = NULL, *tail = NULL;

PRIVATE int num_items = 0;

PUBLIC void enqueue(Item i)
{
    struct node *new_node;
    if ((new_node = malloc(sizeof(struct node))) == NULL)
    {
        printf("Error, malloc failed in enqueue.\n");
        exit(EXIT_FAILURE);
    }

    new_node->item = i;
    new_node->next = NULL;
    num_items++;

    if (head == NULL)
    {
        head = tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

PUBLIC Item dequeue(void)
{
    if (!is_empty())
    {
        struct node *temp = head;
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
