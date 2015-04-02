#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void terminate(const char *message);

struct node {
    Item value;
    struct node *next;
};

struct queue_type {
    struct node *first;
    struct node *last;
    int len;
};

Queue create(void)
{
    Queue q;
    if ((q = malloc(sizeof(struct queue_type))) == NULL)
    {
        printf("Error, malloc failed in create()\n");
        exit(EXIT_FAILURE);
    }
    q->first = NULL;
    q->last = NULL;
    q->len = 0;
    return q;
}

void destroy(Queue q)
{
    empty_queue(q);
    free(q);
}

void enqueue(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error, queue is full.\n");

    struct node *new_node;
    if ((new_node = malloc(sizeof(struct node))) == NULL)
    {
        terminate("Error, malloc failed in enqueue()\n");
    }
    new_node->value = i;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->first = q->last = new_node;
    }
    else
    {
        q->last->next = new_node;
        q->last = new_node;
    }
    q->len++;
}

Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");

    Item i = q->first->value;
    struct node *temp = q->first;

    if (q->first == q->last)
        q->first = q->last = NULL;
    else
        q->first = q->first->next;

    free(temp);
    q->len--;
    return i;
}

Item peek_front(const Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");
    return q->first->value;
}

Item peek_end(const Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");
    return q->last->value;
}

bool is_empty(const Queue q)
{
    return q->len == 0;
}

bool is_full(const Queue q)
{
    return false;
}

void empty_queue(Queue q)
{
    while (!is_empty(q))
    {
        dequeue(q);
    }
}

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
