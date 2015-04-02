#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    Stack s = create();
    char ch;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '{' || ch == '(')
        {
            push(s, ch);
        }
        else if (ch == '}' && pop(s) != '{')
        {
            printf("Parentheses not nested properly.");
            break;
        }
        else if (ch == ')' && pop(s) != '(')
        {
            printf("Parentheses not nested properly.");
            break;
        }
    }

    if (is_empty(s))
        printf("All parentheses and braces are matched");
    else
        printf("Parentheses and braces are not matched");

    destroy(s);

    return 0;
}
