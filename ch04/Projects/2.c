#include <stdio.h>

int main(void)
{
    int num, n1, n2, n3;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);
 
    n1 = num / 100;
    n2 = (num % 100) / 10;
    n3 = (num % 100) % 10;
    printf("The reversal is: %d%d%d", n3, n2, n1);

    return 0;
}
