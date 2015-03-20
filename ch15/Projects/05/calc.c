#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

/* Processes a single input character to determine appropriate response */
void process_character(char ch) {

    int operand1, operand2;
    switch(ch) {

        case '0':   push(0); break;
        case '1':   push(1); break;
        case '2':   push(2); break;
        case '3':   push(3); break;
        case '4':   push(4); break;
        case '5':   push(5); break;
        case '6':   push(6); break;
        case '7':   push(7); break;
        case '8':   push(8); break;
        case '9':   push(9); break;

        case '+':   push(pop() + pop());
                    break;

        case '-':   operand2 = pop();
                    operand1 = pop();
                    push(operand1 - operand2);
                    break;

        case '*':   push(pop() * pop());
                    break;

        case '/':   operand2 = pop();
                    operand1 = pop();
                    push(operand1 / operand2);
                    break;
            
        case '=':   printf("Value of expression: %d\n", pop());
                    break;

        case ' ':   break;

        default:    exit(EXIT_FAILURE);

    }
}

int main(void)
{
    char ch;

    while (true) {

        printf("Enter an RPN expression: ");

        while ((ch = getchar()) != EOF && ch != '\n')
            process_character(ch);
        
    }
    return 0;
}
