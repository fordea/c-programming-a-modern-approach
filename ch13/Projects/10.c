#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

void reverse_name(char *name);

int main(void)
{
    char name[MAX_LEN+1];
    printf("Enter a first and last name: ");

    fgets(name, sizeof(name), stdin); 
    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name, initial;

    while (*p && *p == ' ')
        p++;
    initial = *p++;

    while (*p && *p++ != ' ');

    while (*p && *p != '\n')
        putchar(*p++);
    printf(", %c.", initial);
}
