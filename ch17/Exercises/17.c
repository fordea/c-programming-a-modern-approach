#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparison(const void *i, const void *j);

int main(void)
{
    int a[100], i;
    srand(time(NULL));

    printf("Unsorted array:\n");
    for (i = 0; i < 100; i++) {
        a[i] = rand() % 100 + 1; // generate random number between 1 and 100
        printf("%d ", a[i]);
    }
    printf("\n\n");

    /* qsort(a + 49, 50, sizeof(int), comparison); */
    qsort(a + (sizeof(a) / sizeof(a[0])) - 50, 50, sizeof(int), comparison);

    printf("Sorted second half:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

int comparison(const void *i, const void *j)
{
    return *((int *)i) - *((int *)j);
}
