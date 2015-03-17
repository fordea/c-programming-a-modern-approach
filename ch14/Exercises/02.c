#include <stdio.h>

#define NELEMS(a) ((unsigned int) (sizeof(a)) / (sizeof(a[0])))

int main(void)
{
    int a[932];
    printf("%zu\n", NELEMS(a));
}
