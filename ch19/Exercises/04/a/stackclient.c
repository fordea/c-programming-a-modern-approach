#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    Stack s1 = create();
    Stack s2 = create();
    push(s1, 39);
    push(s2, 83);
    printf("%d\n", pop(s1));
    printf("%d\n", pop(s2));
    destroy(s1);
    destroy(s2);
}
