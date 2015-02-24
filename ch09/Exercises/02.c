#include <stdio.h>

int check(int, int, int);

int main(void)
{

    printf("%d and %d: %d\n", 5, 10, check(5, 10, 15));
    printf("%d and %d: %d\n", 2, 3, check(2, 3, 1));
    return 0;
}

/* Checks whether the values x and y fall in the range
 * of 0 to n - 1. Returns 1 if true, 0 if false. 
 */
int check(int x, int y, int n)
{
    if ((x >= 0 && x < n - 1) && (y >= 0 && y < n - 1))
        return 1;

    return 0;
}
