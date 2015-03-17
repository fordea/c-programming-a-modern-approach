#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REM(n) ((n) % 4)
#define PROD(x, y) ((x) + (y) < 100 ? 1 : 0)

int main(void)
{
    int x = 3, y = 100;
    float a = 5.6, b = 10.2;
    printf("%f\n", CUBE(a));
    printf("%d\n", REM(x));
    printf("%d\n", PROD(x, y));
}
