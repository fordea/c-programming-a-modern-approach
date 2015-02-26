#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = 4;
    printf("%d! = %d",  n, fact(n)); 
    return 0;
}

/*Returns the factorial of n*/
int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n - 1);
}
