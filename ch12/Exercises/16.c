#include <stdio.h>
#include <stdbool.h>

#define DAYS 7
#define HOURS 24

int *find_largest(int a[], int n);

int main(void)
{
    int temperatures[DAYS][HOURS] = {[1][15] = 31, [5][12] = 24, [6][2] = 35};
    int *week_largest, *day_largest;
    int day;

    week_largest = temperatures[0];

    for (day = 0; day < DAYS; day++) {
        day_largest = find_largest(temperatures[day], HOURS);

        printf("Day %d largest: %d\n", day, *day_largest);
        if (*day_largest > *week_largest)
            week_largest = day_largest;
    }
    printf("Week largest: %d\n", *week_largest);

    return 0;
}

/* Returns a pointer to the array element containing the largest value */
int *find_largest(int a[], int n)
{
    int *p, *largest;

    for (p = a, largest = a; p < a + n; p++) {
        if (*p > *largest)
            largest = p;
    }
    return largest;
}
