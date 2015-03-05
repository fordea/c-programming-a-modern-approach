#include <stdio.h>

double inner_product(const double *a, const double *b, int n);

int main(void)
{
    const double a[5] = {1, 2, 3, 4, 5};
    const double b[5] = {1, 2, 3, 4, 5};

    printf("Inner product: %f", inner_product(a, b, 5));
    return 0;
}

double inner_product(const double *a, const double *b, int n)
{
    double sum = 0;
    const double *a_ptr, *b_ptr;

    for (a_ptr = a, b_ptr = b; a_ptr < a + n && b_ptr < b + n; a_ptr++, b_ptr++) {
        printf("%f * %f = %f\n", *a_ptr, *b_ptr, *a_ptr * *b_ptr);
        sum += *a_ptr * *b_ptr;
    }

    return sum;
}

