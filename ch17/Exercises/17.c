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

    qsort(a, 100, sizeof(int), comparison);

    printf("Sorted array:\n");
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
