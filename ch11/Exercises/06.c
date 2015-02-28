#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    int a[10] = {38, 4, 38, 84, 65, 9, 5, 14, 76, 49};
    int largest = 0, second_largest = 0, i;

    printf("Array contents: ");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");

    find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &second_largest);
    printf("Largest: %d, Second Largest: %d\n", largest, second_largest);
    return 0;
}

/* finds the two largest values in an array */
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if (a[i] <= *largest && a[i] > *second_largest) {
            *second_largest = a[i];
        }
        printf("Iteration %d: Largest: %d, Second Largest: %d\n",
                i, *largest, *second_largest);
    } 
}

