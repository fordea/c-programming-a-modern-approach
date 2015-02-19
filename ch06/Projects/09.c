#include <stdio.h>

int main(void)
{
    float loan, interest_rate, monthly_payment;
    int no_of_payments;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter number of payments: ");
    scanf("%d", &no_of_payments);

    float monthly_interest = ((interest_rate / 100) / 12) + 1;

    int i;
    for (i = 1; i <= no_of_payments; i++) {
        loan *= monthly_interest;
        loan -= monthly_payment;
        printf("Balance remaining after %d month(s): $%.2f\n", i, loan);
    }


    return 0;
}
