#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = argc - 1; i >= 1; i--)
        printf("%s ", argv[i]);

    printf("\n");

    char **p;
    for (p = argv + argc - 1; p > argv; p--)
        printf("%s ", *p);
    return 0;
}
