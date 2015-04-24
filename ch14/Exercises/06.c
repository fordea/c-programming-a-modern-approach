#include <stdio.h>
#include <math.h>

#define DISP(f,x) (printf("%s(%g) = %g\n", (#f), (x), (f(x))))
#define DISP2(f,x,y) (printf("%s(%g,%g) = %g\n", (#f), (x), (y), (f((x),(y)))))

int main(void)
{
    DISP(sqrt, 1024.0);
    DISP2(pow, 32.0, 2.0);
    return 0;
}
