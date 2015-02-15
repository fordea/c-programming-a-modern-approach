#include <stdio.h>

int main(void)
{
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    printf("$20 bills: %d\n", amount / 20);
    amount -= (amount / 20) * 20;
    printf("$10 bills: %d\n", amount / 10);
    amount -= (amount / 10) * 10;
    printf(" $5 bills: %d\n", amount / 5);
    amount -= (amount / 5) * 5;
    printf(" $1 bills: %d\n", amount / 1);
    amount -= (amount / 1) * 1;

    return 0;
}
