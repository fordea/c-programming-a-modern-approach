#include <stdio.h>

int main(void)
{
    int area_code, exchange, subscriber_number;

    printf("Enter a telephone number (xxx) xxx-xxxx: ");
    scanf(" (%d )%d -%d", &area_code, &exchange, &subscriber_number);

    printf("You entered %d.%d.%d", area_code, exchange, subscriber_number);

    return 0;
}
