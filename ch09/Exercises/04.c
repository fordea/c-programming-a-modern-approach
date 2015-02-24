#include <stdio.h>

int day_of_year(int, int, int);

int main(void)
{
    printf("Day of year for date %.2d/%.2d/%.4d: %d\n", 4, 10, 2008,
            day_of_year(4, 10, 2008)); //Leap year
    printf("Day of year for date %.2d/%.2d/%.4d: %d\n", 4, 10, 2009,
            day_of_year(4, 10, 2009)); //Non leap year
    return 0;
}

/* Returns the day in a year for a given
 * date */
int day_of_year(int month, int day, int year)
{
    int i;
    for (i = 1; i < month; i++) {
        switch(i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day += 30;
            case 2:
                if (((year % 4 == 0) && (year % 100 != 0))
                   || (year % 400 == 0))
                    day += 29;
                else
                    day += 28;
        }
    }

    return day;
}
