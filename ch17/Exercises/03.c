#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *p, *p2;
    if ((p = malloc(n * sizeof(int))) == NULL) {
        return NULL;
    }

    for (p2 = p; p2 < p + n; p2++)
        *p2 = initial_value;

    return p;
}

int main(void)
{
    int *arr = create_array(20, 7);
    int *p = arr;

    while (p < arr + 20)
        printf("%d ", *p++);
    printf("\n");
    
}
