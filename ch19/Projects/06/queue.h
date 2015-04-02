#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

/* Creates and returns a Queue of size n */
Queue create(int n);

/* Destroys the Queue q */
void destroy(Queue q);

/* Appends Item i to the end of the Queue q */
void enqueue(Queue q, Item i);

/* Removes and returns Item i from the front of the Queue q */
Item dequeue(Queue q);

/* Returns but doesn't remove Item i from the front of the Queue q */
Item peek_front(Queue q);

/* Returns but doesn't remove Item i from the end of the Queue q */
Item peek_end(Queue q);

/* Returns true if the Queue q is empty */
bool is_empty(Queue q);

/* Returns true if the Queue q is full */
bool is_full(Queue q);

/* Removes all items from Queue q */
void empty_queue(Queue q);


#endif
