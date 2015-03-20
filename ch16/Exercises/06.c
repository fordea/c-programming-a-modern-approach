#include <stdio.h>

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
    long seconds;
    printf("Enter a number (seconds) between 0 and 86400: ");
    scanf("%ld", &seconds);

    while (seconds <=1 || seconds >= 86400) {
        printf("Error, must enter a number (seconds) between 0 and 86400: ");
        scanf("%ld", &seconds);
    }

    struct time t1 = split_time(seconds);

    printf("%ld seconds in hh:mm:ss: %.2d:%.2d:%.2d\n", seconds,
            t1.hours, t1.minutes, t1.seconds);
    return 0; 
}

struct time split_time(long total_seconds)
{
    struct time newtime;

    newtime.hours = total_seconds / 3600;
    total_seconds %= 3600;

    newtime.minutes = total_seconds / 60;
    total_seconds %= 60;

    newtime.seconds = total_seconds;

    return newtime;
}
