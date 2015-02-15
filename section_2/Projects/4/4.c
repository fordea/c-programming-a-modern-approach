#include <stdio.h>

float amount;

int main(void)
{
    printf("Enter an amount: ");
    scanf("%f", &amount);
    printf("with tax added: $%.2f", amount * 1.05f);

    return 0;
}
