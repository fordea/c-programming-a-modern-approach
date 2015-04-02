#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

void process_character(Stack s, char ch);

int main(void)
{
    Stack s = create();
    char ch;

    while (true) {

        printf("Enter an RPN expression: ");

        while ((ch = getchar()) != EOF && ch != '\n')
            process_character(s, ch);

    }

    destroy(s);

    return 0;
}

/* processes a character to perform an operation on the stack
 */
void process_character(Stack s, char ch)
{
    int operand1, operand2;

    if (isdigit(ch))
    {
        push(s, ch - '0');
        return;
    }

    switch(ch)
    {
        case '+':   push(s, pop(s) + pop(s));
                    break;

        case '-':   operand2 = pop(s);
                    operand1 = pop(s);
                    push(s, operand1 - operand2);
                    break;

        case '*':   push(s, pop(s) * pop(s));
                    break;

        case '/':   operand2 = pop(s);
                    operand1 = pop(s);
                    push(s, operand1 / operand2);
                    break;

        case '=':   printf("Value of expression: %d\n", pop(s));
                    break;

        case ' ':   break;

        default:    exit(EXIT_FAILURE);

    }
}
