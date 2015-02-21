#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, initial;

    printf("Enter a first and last name: ");
    while ((ch = getchar()) == ' '); //Skip initial white space until first char
    initial = ch;
    while ((ch = getchar()) != ' '); //Skip chars after first char until whitespace

    while ((ch = getchar()) != '\n') {
        if (ch != ' ')
            putchar(ch);
    }
    printf(", %c.", initial);

    return 0;
}
