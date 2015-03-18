#include <stdio.h>

#define ERROR(str, arg) (fprintf(stderr, (str), (arg)))

int main(void)
{
    int index = 10;
    ERROR("Range error: index = %d\n", index);
}
