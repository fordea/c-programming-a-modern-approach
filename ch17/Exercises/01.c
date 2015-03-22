#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int bytes)
{
    void *p;

    if ((p = malloc(bytes)) == NULL) {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

int main(void)
{
    char *p = my_malloc(10);
}
