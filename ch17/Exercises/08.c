#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

struct node *top = NULL;

void make_empty(void);
int is_empty(void);
bool push(int i);
int pop(void);

int main(void)
{
    push(10);
    push(12);
    push(20);
    printf("Popped %d\n", pop());

    make_empty();
    printf("Is empty: %d", is_empty());
}

void make_empty(void)
{
    struct node *next_node;
    while (top) {
        next_node = top->next;
        free(top);
        top = next_node;
    }
}

int is_empty(void)
{
    return top == NULL;
}

bool push(int i)
{
    struct node *new_node;

    if ((new_node = malloc(sizeof(struct node))) == NULL) {
        printf("Error: malloc failed in push\n");
        return false;
    }

    new_node->value = i;
    new_node->next = top;
    top = new_node;
    return true;
}

int pop(void)
{
    if (is_empty()) {
        printf("Error, stack underflow.");
        exit(EXIT_FAILURE);
    }

    int value = top->value;
    struct node *next_node = top->next;
    free(top);
    top = next_node;
    return value;
}
