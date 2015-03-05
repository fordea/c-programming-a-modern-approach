#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key);

int main(void)
{
    printf("%d\n", search((int []){1, 2, 3, 4, 5}, 5, 9));
    return 0;
}

bool search(const int a[], int n, int key)
{
    const int *p = a;

    while (p < a + n) {
        if (key == *p++)
            return true;
    }
    return false;
}
