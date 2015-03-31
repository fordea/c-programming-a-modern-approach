#include <stdio.h>
#include "queue.h"

int main(void)
{
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("dequeued: %d\n", dequeue());
    printf("first in queue: %d\n", get_first());
    printf("last in queue: %d\n", get_last());
    printf("dequeued: %d\n", dequeue());
    enqueue(63);
    enqueue(233);
    enqueue(783);
    printf("dequeued: %d\n", dequeue());
    printf("Is empty? %d\n", is_empty());
    printf("first in queue: %d\n", get_first());
    printf("last in queue: %d\n", get_last());
    printf("Items currently in queue: %d\n", items_in_queue());
}
