#include <stdio.h>

void store_zeros(int a[], int n);

int main(void)
{
    return 0;
}

void store_zeros(int a[], int n)
{
    int *p;
    for (p = a; p < a + n; p++)
        *p = 0;
}
