#include <stdio.h>

int count_spaces(const char *s);

int main(void)
{
    const char str1[] = "Testing the count spaces function.";
    printf("Number of spaces: %d", count_spaces(str1));
    return 0;
}

int count_spaces(const char *s)
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
    return count;
}

