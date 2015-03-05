#include <stdio.h>

#define ROWS 3
#define COLS 5

int sum_two_dimensional_array(const int *a, int n);

int main(void)
{
    const int a[ROWS][COLS] = { {1, 2, 3, 4, 5},
                                {4, 8, 8, 12, 3},
                                {3, 4, 8, 3, 12}};

    printf("Sum: %d", sum_two_dimensional_array(a[0], ROWS * COLS));

    return 0;
}

int sum_two_dimensional_array(const int *a, int n)
{
    int sum = 0;
    const int *p;
    for (p = a; p < a + n; p++)
        sum += *p;
    return sum;
}
