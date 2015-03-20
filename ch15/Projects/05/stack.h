#ifndef STACK_H
#define STACK_H

/* Empties the stack */
void make_empty(void);

/* Returns true if stack is empty, else false */
bool is_empty(void);

/* Returns true if stack is full, else false */
bool is_full(void);

/* Pushes integer i onto the top of the stack */
void push(int i);

/* Removes the top item from the stack and returns it */
int pop(void);

#endif
