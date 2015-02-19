#include <stdio.h>

int main(void)
{
    int days_in_month, week_start;

    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &week_start);

    int i;
    int iterations_needed = days_in_month + (week_start - 1);
    int day = 1; 

    for (i = 1; i <= iterations_needed; i++) {
        if (i < week_start)
            printf("   ");
        else
            printf("%3d", day++);

        if (i % 7 == 0)
            printf("\n");
    }

    return 0;
}
