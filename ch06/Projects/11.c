#include <stdio.h>

int main(void)
{
    int n;
    float e = 1.0f;

    printf("Enter a number: ");
    scanf("%d", &n);

    int i, factorial = 1;
    for (i = 1; i <= n; i++) {

        factorial *= i;
        e += (1.0f / factorial);
    }

    printf("%f", e);
    return 0;
}
