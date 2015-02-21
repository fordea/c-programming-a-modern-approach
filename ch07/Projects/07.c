#include <stdio.h>

int main(void)
{
    int n1, d1, n2, d2, n_res, d_res;
    char operator;

    printf("Enter two fractions separated by +, -, * or /: ");
    scanf("%d /%d %c %d /%d", &n1, &d1, &operator, &n2, &d2);

    switch (operator) {
        case '+':
            n_res= n1 * d2 + n2 * d1;
            d_res= d1 * d2;
            break;
        case '-':
            n_res= n1 * d2 - n2 * d1;
            d_res= d1 * d2;
            break;
        case '*':
            n_res= n1 * n2;
            d_res= d1 * d2;
            break;
        case '/':
            n_res= n1 * d2;
            d_res= n2 * d1;
            break;
    }

    /* Find the GCD of the resulting fraction */
    int temp, n_temp = n_res, gcd = d_res;
    while (n_temp != 0) {
        temp = gcd % n_temp;
        gcd = n_temp;
        n_temp = temp;
    }

    /* Print result in its simplest form */
    if (n_res / gcd == d_res / gcd)
        printf("Result is: %d", n_res / gcd);
    else if (n_res > d_res)
        printf("Result is: %d %d/%d", n_res / d_res, n_res % d_res, d_res);
    else
        printf("Result is: %d/%d", n_res / gcd, d_res / gcd);

    return 0;
}
