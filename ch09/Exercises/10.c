#include <stdio.h>

#define SIZE sizeof(a) / sizeof(a[0])

int largest_element(int a[], int length);
float average_of_elements(int a[], int length);
int positive_element_count(int a[], int length);

int main(void)
{
    int i, a[10] = {1, 3, 8, 20, 12, 27, 0, 32, 12, 10};

    printf("a[] contains: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Largest element in a[]: %d\n", largest_element(a, SIZE));
    printf("Average of elements in a[]: %.2f\n", average_of_elements(a, SIZE));
    printf("Number of positive elements in a[]: %d\n", positive_element_count(a, SIZE));

    return 0;
}


/* Returns the largest element in a[] */
int largest_element(int a[], int length)
{
    int i, largest = a[0];

    for (i = 1; i < length; i++) {
        if (a[i] > largest)
            largest = a[i];
    }

    return largest;
}

/*Returns the average of all elements in a[] */
float average_of_elements(int a[], int length)
{
    int i;
    float average = a[0];

    for (i = 1; i < length; i++)
        average += a[i];

    return average / length;
}

/*Returns the number of positive elements in a[] */
int positive_element_count(int a[], int length)
{
    int i, positive_count = 0;

    for (i = 0; i < length; i++) {
        if (a[i] > 0)
            positive_count++;
    }

    return positive_count;
}

