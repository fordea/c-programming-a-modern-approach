#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int sum = 0;
    char **p;

    for (p = argv + 1; p < argv + argc; p++)
        sum += atoi(*p);

    printf("Total: %d", sum);
    return 0;
}
