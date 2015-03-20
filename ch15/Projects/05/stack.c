#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

/* Prints appropriate message for a stack overflow situation and terminates execution*/
int stack_overflow(void);
/* Prints appropriate message for a stack underflow situation and terminates execution */
int stack_underflow(void);

/* external variables */
int contents[STACK_SIZE], top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int stack_overflow(void)
{
        printf("Expression is too complex");
        exit(EXIT_FAILURE);
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int stack_underflow(void)
{
        printf("Not enough operands in expression");
        exit(EXIT_FAILURE);
}
