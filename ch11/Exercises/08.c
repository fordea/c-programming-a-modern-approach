#include <stdio.h>

#define SIZE sizeof(a) / sizeof(a[0])
int *find_largest(int a[], int n);

int main(void)
{
    int i, a[10] = {1, 48, 24, 83, 76, 34, 74, 12, 84, 23};

    printf("Array contents: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);

    printf("\nLargest: %d", *find_largest(a, SIZE));

    return 0;
}

/* Returns a pointer to the array element containing the largest value */
int *find_largest(int a[], int n)
{
    int i, index_largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[index_largest])
            index_largest = i;
    }

    return &a[index_largest];
}
