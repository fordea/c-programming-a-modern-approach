#include <stdio.h>

int x;

int main(void)
{
    printf("Enter a value: ");
    scanf("%d", &x);
    printf("%d", ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);

    return 0;
}
