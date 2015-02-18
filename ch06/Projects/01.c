#include <stdio.h>

int main(void)
{
    float number, largest;
    largest = 0.0f;

    for(;;) {
        printf("Enter a number(0 to terminate): ");
        scanf("%f", &number);
    
        if (number == 0.0f)
            break;
    
        if (number > largest)
            largest = number;
    }
    printf("The largest number entered was: %.3f", largest);

    return 0;
}
