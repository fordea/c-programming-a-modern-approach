#include <stdio.h>

int main(void)
{
    int income;
    float tax_due;
    
    printf("Enter the amount of taxable income: ");
    scanf("%d", &income);

    if (income <= 750)
        tax_due = income * 0.01f;
    else if (income <= 2250)
        tax_due = 7.50f + ((income - 750) * 0.02f);
    else if (income <= 3750)
        tax_due = 37.50f + ((income - 2250) * 0.03f);
    else if (income <= 5250)
        tax_due = 82.50f + ((income - 3750) * 0.04f);
    else if (income <= 7000)
        tax_due = 142.50f + ((income - 5250) * 0.05f);
    else 
        tax_due = 230.00f + ((income - 7000) * 0.06f);

    printf("Tax due: $%.2f", tax_due);

    return 0;
}
