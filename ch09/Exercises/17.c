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
    int i, sum = 1;
    for (i = 2; i <= n; i++)
        sum *= i;

    return sum;
}
