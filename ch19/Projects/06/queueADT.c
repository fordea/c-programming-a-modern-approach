#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void terminate(char *message);

struct queue_type {
    Item *contents;
    int first;
    int next;
    int len;
    int max_size;
};

Queue create(int n)
{
    Queue q;
    if ((q = malloc(sizeof(struct queue_type))) == NULL)
    {
        printf("Error, malloc failed in create()\n");
        exit(EXIT_FAILURE);
    }
    if ((q->contents = malloc(n * sizeof(Item))) == NULL)
    {
        printf("Error, malloc failed in create()\n");
        exit(EXIT_FAILURE);
    }
    q->first = 0;
    q->next = 0;
    q->len = 0;
    q->max_size = n;
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void enqueue(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error, queue is full.\n");
    q->contents[q->next++] = i;
    q->len++;
}

Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");
    Item i = q->contents[q->first++];
    q->len--;
    return i;
}

Item peek_front(Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");
    return q->contents[q->first];
}

Item peek_end(Queue q)
{
    if (is_empty(q))
        terminate("Error, queue is empty.\n");
    return q->contents[q->next - 1];
}

bool is_empty(Queue q)
{
    return q->len == 0;
}

bool is_full(Queue q)
{
    return q->len == q->max_size;
}

void empty_queue(Queue q)
{
    while (!is_empty(q))
    {
        dequeue(q);
    }
}

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
