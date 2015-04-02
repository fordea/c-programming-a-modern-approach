#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

/* Appends Item i to the end of the queue */
void enqueue(Item i);

/* Removes and returns Item i from the front of the queue */
Item dequeue(void);

/* Returns but doesn't remove Item i from the front of the queue */
Item get_first(void);

/* Returns but doesn't remove Item i from the end of the queue */
Item get_last(void);

/* Returns true if the queue is empty */
bool is_empty(void);

#endif
