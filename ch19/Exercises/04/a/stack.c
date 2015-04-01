#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 100

static void terminate(char *message);

struct stack_type {
    int contents[MAX];
    int top;
};

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    s->top = 0;
    return s;
}

void destroy(Stack s)
{
    free(s);
}

void make_empty(Stack s)
{
    s->top = 0;
}

bool is_empty(const Stack s)
{
    return s->top == 0;
}

bool is_full(const Stack s)
{
    return s->top == MAX - 1;
}

void push(Stack s, Item i)
{
    if (is_full(s))
        terminate("Error, stack overflow.");
    s->contents[s->top++] = i;
}

Item pop(Stack s)
{
    if (is_empty(s))
        terminate("Error, stack underflow.");
    return s->contents[--s->top];
}

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
