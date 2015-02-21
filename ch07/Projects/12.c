#include <stdio.h>
#include <ctype.h>

int main(void)
{
    float num = 0.0f, running_total = 0.0f;
    char ch;

    printf("Enter an expression: ");
    scanf("%f", &running_total);
    
    while ((ch = getchar()) != '\n') {

        switch (ch) {
            case '+':
                scanf("%f", &num);
                running_total += num;
                break;
            case '-':
                scanf("%f", &num);
                running_total -= num;
                break;
            case '*':
                scanf("%f", &num);
                running_total *= num;
                break;
            case '/':
                scanf("%f", &num);
                running_total /= num;
                break;
            default:
                continue;
        }
    }
    printf("Value of expression: %.2f", running_total);

    return 0;
}
