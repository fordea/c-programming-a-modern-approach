#include <stdio.h>
#include <stdbool.h>

#define EARLIER -1
#define SAME 0
#define LATER 1

#define FEBRUARY 1

struct date {
    int month;
    int day;
    int year;
};

const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*Returns true if leap year, else false */
bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Returns the day of year that corresponds to date d */
int day_of_year(struct date d)
{
    int month, total_days = d.day;
    for (month = 0; month < d.month - 1; month++) {
        total_days += month_days[month];

        if (month == FEBRUARY && is_leap_year(d.year))
            total_days++;
    }

    return total_days;
}

/* Returns -1 if d1 is earlier than d2, 1 if d1 is later than d2,
   or 0 if the same */
int compare_dates(struct date d1, struct date d2)
{
    int comparison;

    /* Compare Years */
    if (d1.year < d2.year)
        comparison = EARLIER;
    else if (d1.year < d2.year)
        comparison = LATER;

    /*Years are the same so compare num days in year */
    else {
        int d1_days = day_of_year(d1);
        int d2_days = day_of_year(d2);

        if (d1_days > d2_days)
            comparison = EARLIER;
        else if (d1_days < d2_days)
            comparison = LATER;
        else
            comparison = SAME;

    }

    return comparison;
}


int main(void)
{
    struct date d1, d2;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &d2.month, &d2.day, &d2.year);



    switch (compare_dates(d1, d2)) {
        case -1: printf("%d/%d/%d is earlier than %d/%d/%d\n",
                 d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
                 break;
        case 1:  printf("%d/%d/%d is earlier than %d/%d/%d\n",
                 d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
                 break;
        case 0:  printf("%d/%d/%d is the same as %d/%d/%d\n",
                 d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
                 break;
    }   

    return 0;
}
