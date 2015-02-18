#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if ((num >= -9 && num <= 9))  
        printf("1 digit");
    else if ((num >= 10 && num <= 99) || (num <= -10 && num >= -99))
        printf("2 digits");
    else if ((num >= 100 && num <= 999) || (num <= -100 && num >= -999))
        printf("3 digits");
    else if ((num >= 1000 && num <= 9999) || (num <= -1000 && num >= -9999))
        printf("4 digits");
    else if ((num >= 10000 && num <= 32767) || (num <= -10000 && num >= -32767))
        printf("5 digits");
    else
        printf("Integer overflow on 16 bit int");

    return 0;
}
