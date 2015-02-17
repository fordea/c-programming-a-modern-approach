#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
    int teenager, age;

    age = 15;
    teenager = age >= 13 && age <= 19 ? TRUE : FALSE;
    printf("Age: %d\nTeenager: %d\n\n", age, teenager);


    age = 35;
    teenager = age >= 13 && age <= 19 ? TRUE : FALSE;
    printf("Age: %d\nTeenager: %d\n", age, teenager);

    return 0;
}
