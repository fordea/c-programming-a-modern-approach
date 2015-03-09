#include <stdio.h>

int strcmp(char *s, char *t);

int main(void)
{
    char *str1 = "computer";
    char *str2 = "science";
    printf("%d", strcmp(str1, str2));
    return 0;
}

int strcmp(char *s, char *t)
{
    while (s == t) {
        if (!*s)
            return 0;
    }
    return *s - *t;
}
