#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 100

typedef struct queue_type {
    Item contents[MAX];
    int idx_first_item;
    int idx_new_item;
    int num_items;
} *Queue;

/* Appends Item i to the end of the Queue q */
void enqueue(Queue q, Item i);

/* Removes and returns Item i from the front of the Queue q */
Item dequeue(Queue q);

/* Returns but doesn't remove Item i from the front of the Queue q */
Item get_first(Queue q);

/* Returns but doesn't remove Item i from the end of the Queue q */
Item get_last(Queue q);

/* Returns true if the Queue q is empty */
bool is_empty(Queue q);

#endif
