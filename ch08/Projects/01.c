#include <stdio.h>

int main(void)
{
    int no_of_digits_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        no_of_digits_seen[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s): ");
    for (n = 0; n < 10; n++) {
        if (no_of_digits_seen[n] > 1)
            printf("%ld ", n);
    }

    return 0;
}
