#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("The reversal is: ");
    do {
        printf("%d", n % 10);
        n /= 10;

    } while (n != 0);

    return 0;
}
