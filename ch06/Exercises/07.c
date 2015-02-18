#include <stdio.h>

int main(void)
{
    int i;
    for (i = 9384; i > 0; i /= 10) { printf("%d ", i); }

    return 0;
}
