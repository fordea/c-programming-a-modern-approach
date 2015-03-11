#include <stdio.h>

int main(void)
{
    int number, tens, ones;
    char *ones_tostr[] = {"one.", "two.", "three", "four.", "five.",
                          "six.", "seven.", "eight.", "nine."};

    char *teens_tostr[] = {"ten.", "eleven.", "twelve.", "thirteen.",
                           "fourteen.", "fifteen.", "sixteen.", "seventeen.",
                           "eighteen.", "nineteen."};

    char *tens_tostr[] = {"twenty-", "thirty-", "forty-", "fifty-",
                          "sixty-", "seventy-", "eighty-", "ninety-"};

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number < 1 || number > 99) {
        printf("Error, please enter a number between 1 and 99.");
        return 0;
    }

    tens = number / 10;
    ones = number % 10;

    printf("You entered the number ");
    
    if (tens == 0) //ones
        printf("%s", ones_tostr[ones-1]);
    else if (tens == 1) //teens
        printf("%s", teens_tostr[ones]);
    else //tens from 20 onward
        printf("%s%s", tens_tostr[tens-2], ones_tostr[ones-1]);

    return 0;
}
