#include <stdio.h>
#include <math.h>

#define DISP(f,x) (printf("%s(%g) = %g\n", (#f), (x), (f(x))))

int main(void)
{
    DISP(sqrt, 3.0);
}
