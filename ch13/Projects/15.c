#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

int evaluate_RPN_expression(const char *expression);

/* external variables */
int contents[STACK_SIZE], top = 0;

int stack_overflow(void)
{
    printf("Expression is too complex");
    exit(EXIT_FAILURE);
}

int stack_underflow(void)
{
    printf("Not enough operands in expression");
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
    char expression[50+1];

    for(;;) {
        make_empty();
        printf("Enter an RPN expression: ");
        fgets(expression, sizeof(expression), stdin);
        printf("Result: %d\n", evaluate_RPN_expression(expression));
    }
    return 0;
}

int evaluate_RPN_expression(const char *expression)
{
    int operand1, operand2;
    for (; *expression; expression++) {
        if (isdigit(*expression)) {
                push(*expression - '0');
        } else if (isspace(*expression)) {
            continue;
        } else {
            switch(*expression++) {
                case '+':   push(pop() + pop()); break;
                case '-':   operand2 = pop();
                            operand1 = pop();
                            push(operand1 - operand2);
                            break;
                case '*':   push(pop() * pop()); break;
                case '/':   operand2 = pop();
                            operand1 = pop();
                            push(operand1 / operand2);
                            break;
                case '=':   return(pop());
                default:    exit(EXIT_FAILURE);
            }
        }
    }
}
