#include <stdio.h>

int main(void)
{
    int no_of_digits_seen[10] = {0};
    int digit;
    long n;

    for (;;) {    

        printf("Enter a number (0 to terminate): ");
        scanf("%ld", &n);
        if (n <= 0)
            break;

        while (n > 0) {
            digit = n % 10;
            no_of_digits_seen[digit]++;
            n /= 10;
        }

        printf("%-15s0  1  2  3  4  5  6  7  8  9\n", "Digit:");
        printf("%-15s", "Occurences:");
        for (n = 0; n < 10; n++) {
            printf("%-3d", no_of_digits_seen[n]);
            no_of_digits_seen[n] = 0;
        }
        printf("\n\n");
    }

    return 0;
}
