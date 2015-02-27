#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char ch, contents[STACK_SIZE];
int top = 0;

int stack_overflow(void)
{
        printf("Stack overflow");
        exit(EXIT_FAILURE);
}

int stack_underflow(void)
{
        printf("Stack underflow");
        exit(EXIT_FAILURE);
}

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

void push(char i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}


int main(void)
{
    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {

        if (ch == '{' || ch == '(') {
            push(ch);
        } else if (ch == '}' && pop() != '{') {
            printf("Parentheses not nested properly.");
            break;
        } else if (ch == ')' && pop() != '(') {
            printf("Parentheses not nested properly.");
            break;
        }
    }

    if (is_empty())
        printf("All parentheses and braces are matched");
    else
        printf("Parentheses and braces are not matched");

    return 0;
}
