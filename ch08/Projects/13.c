#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, initial, surname[20] = {0};
    int i, surname_length = 0;

    printf("Enter a first and last name: ");
    while ((ch = getchar()) == ' '); //Skip initial white space until first char
    initial = ch;
    while ((ch = getchar()) != ' '); //Skip chars after first char until whitespace

    for (i = 0; (ch = getchar()) != '\n' && i < 20; i++) {
        if (ch != ' ') {
            surname[i] = ch;
            surname_length++;
        }
    }

    for (i = 0; i < surname_length; i++)
        printf("%c", surname[i]);

    printf(", %c.", initial);

    return 0;
}
