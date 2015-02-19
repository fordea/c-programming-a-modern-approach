#include <stdio.h>

int main(void)
{
    int n, m, temp;
    
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    while (n != 0) {
       temp = m % n;
       m = n;
       n = temp;
    }
    printf("Greatest common divisor: %d", m);

    return 0;
}

