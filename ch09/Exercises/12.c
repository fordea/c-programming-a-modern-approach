#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void)
{
    double a[5] = {6, 3, 9, 12, 14};
    double b[5] = {2, 17, 8, 5, 10};

    printf("Inner product sum: %lf", inner_product(a, b, 5));

    return 0;
}

double inner_product(double a[], double b[], int n)
{
    int i;
    double sum = 0.0l;

    for (i = 0; i < n; i++)
        sum += a[i] * b[i];

    return sum;
}
