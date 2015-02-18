#include <stdio.h>

int main(void)
{
    int i, j;

    i = 1; j = 2;

    printf("%d\n", (i > j) - (i < j));

    return 0;
}
