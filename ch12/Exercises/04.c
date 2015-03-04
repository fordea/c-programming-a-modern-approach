#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = &contents[0];

void make_empty(void)
{
    top_ptr = &contents[0];
}

bool is_empty(void)
{
    return top_ptr == &contents[0];
}

bool is_full(void)
{
    return top_ptr == &contents[STACK_SIZE];
}

void push(int i)
{
    if (is_full())
        printf("Full\n");
        //stack_overflow();
    else
        *top_ptr++ = i;
}

int pop(void)
{
    if (is_empty())
        printf("Empty\n");
        //stack_underflow();
    else
        return *--top_ptr;
}

int main(void)
{
    return 0;
}
