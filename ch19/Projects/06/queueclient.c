#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q1 = create(5);
    Queue q2 = create(10);

    enqueue(q1, 10);
    enqueue(q1, 39);
    enqueue(q1, 83);
    printf("peek at front of q1: %d\n", peek_front(q1));
    printf("peek at end of q1: %d\n", peek_end(q1));
    printf("Is q1 full? %s\n", is_full(q1) ? "Yes" : "No");
    printf("Is q1 empty? %s\n", is_empty(q1) ? "Yes" : "No");
    printf("Is q2 empty? %s\n", is_empty(q2) ? "Yes" : "No");

    enqueue(q2, 74);
    enqueue(q2, 8);
    printf("dequeued %d from q1\n", dequeue(q1));
    printf("dequeued %d from q2\n", dequeue(q2));

    empty_queue(q1);
    printf("Is q1 empty? %s\n", is_empty(q1) ? "Yes" : "No");

    destroy(q1);
    destroy(q2);

    return 0;
}
