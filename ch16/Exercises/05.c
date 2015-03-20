#include <stdio.h>

#define FEBRUARY 1

#define EARLIER -1
#define SAME 0
#define LATER 1

struct date {
    int month;
    int day;
    int year;
};

const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Returns the day of year that corresponds to date d */
int day_of_year(struct date d)
{
    int month, total_days = d.day;
    for (month = 0; month < d.month - 1; month++) {
        total_days += month_days[month];

        if (month == FEBRUARY)
            if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
                total_days++;
    }

    return total_days;
}

/* Returns -1 if d1 is earlier than d2, 1 if d1 is later than d2,
   or 0 if the same */
int compare_dates(struct date d1, struct date d2)
{
    int comparison;

    if (d1.year > d2.year) { //Later Year
        comparison = LATER;

    } else if (d1.year < d2.year) { //Earlier Year
        comparison = EARLIER; 

    }
    else { //Same Year
        if (d1.month > d2.month) { //Later Month
            comparison = LATER;

        } else if (d1.month < d2.month) { //Earlier Month
            comparison = EARLIER;

        } else { //Same Month
              if (d1.day > d2.day) { //Later Day
                  comparison = LATER;

              } else if (d1.day < d2.day) { //Earlier Day
                  comparison = EARLIER;

              } else { //Same Day
                  comparison = SAME;
              }       
          }
    }

    return comparison;
}

int main(void)
{
    struct date d1 = {3, 12, 2012};
    struct date d2 = {8, 5, 2008};

    printf("Day of year in date %.2d/%.2d/%.4d: %d\n", d1.month, d1.day,
            d1.year, day_of_year(d1));
    printf("Day of year in date %.2d/%.2d/%.4d: %d\n", d2.month, d2.day,
            d2.year, day_of_year(d2));

    printf("Comparison of the dates %.2d/%.2d/%.4d and %.2d/%.2d/%.4d: %d\n",
            d1.month, d1.day, d1.year, d2.month, d2.day, d2.year,
            compare_dates(d1, d2));
    printf("Comparison of the dates %.2d/%.2d/%.4d and %.2d/%.2d/%.4d: %d\n",
            d2.month, d2.day, d2.year, d1.month, d1.day, d1.year,
            compare_dates(d2, d1));
    printf("Comparison of the dates %.2d/%.2d/%.4d and %.2d/%.2d/%.4d: %d\n",
            d1.month, d1.day, d1.year, d1.month, d1.day, d1.year,
            compare_dates(d1, d1));

    return 0;
}
