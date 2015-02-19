#include <stdio.h>

int main(void)
{
    int num, denom, m, n, temp;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    m = num;
    n = denom;

    while (n != 0) {
       temp = m % n;
       m = n;
       n = temp;
    }

    printf("In lowest terms: %d/%d", num / m, denom / m);

    return 0;
}
