#include <stdio.h>

int compute_polynomial(int x);

int main(void)
{
    int x;
    printf("Enter a value for x: ");
    scanf("%d", &x);
    printf("%d", compute_polynomial(x));

    return 0;
}

int compute_polynomial(int x)
{
    return (  (3 * (x * x * x * x * x))
            + (2 * (x * x * x * x))
            - (5 * (x * x * x))
            - (x * x)
            + (7 * x)
            - 6);
}
