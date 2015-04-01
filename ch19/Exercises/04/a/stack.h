#ifndef STACK_H
#define STACK_H

typedef struct node *Stack;
typedef int Item;

Stack create();
void make_empty(Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
