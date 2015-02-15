#include <stdio.h>

int main(void)
{
    float loan, interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest = ((interest_rate / 100) / 12) + 1;

    loan *= monthly_interest;
    loan -= monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", loan);

    loan *= monthly_interest;
    loan -= monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", loan);

    loan *= monthly_interest;
    loan -= monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", loan);

    return 0;
}
