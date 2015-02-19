#include <stdio.h>

int main(void)
{
    float n, e = 1.0f;

    printf("Enter a small floating point number: ");
    scanf("%f", &n);

    int terms = 1, factorial = 1;
    for (;;) {

        factorial *= terms;

        if (1.0f / factorial < n) {
            printf("Term %d (1/%d!): %f which is lower than the threshold: %f\n", terms, terms, 1.0f / factorial, n);
            break;
        }

        e += (1.0f / factorial);
        printf("Term %d (1/%d!): %f, e is currently: %f\n", terms, terms, 1.0f / factorial, e);
        terms++;
    }

    printf("\nAdded %d terms, result is: %f", terms-1, e);
    return 0;
}
