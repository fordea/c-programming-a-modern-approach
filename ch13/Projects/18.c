#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int month, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf(" %2d /%2d /%4d", &month, &day, &year);
    printf("You entered the date : %s %d, %d", *(months + (month-1)), day, year);
}
