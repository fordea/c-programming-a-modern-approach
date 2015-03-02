#include <stdio.h>

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);

int main(void)
{
    int hour, minute, desired_time, departure_time, arrival_time;
    printf("Please enter a time(hh:mm): ");
    scanf("%2d :%2d", &hour, &minute);

    desired_time = (hour * 60) + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d",
            departure_time / 60, departure_time % 60,
            arrival_time / 60, arrival_time % 60);

        return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time)
{
    if (desired_time <= ((8 * 60) + (103 / 2))) {
        *departure_time = 8 * 60;
        *arrival_time = 10 * 60 + 16;

    } else if (desired_time < ((9 * 60) + 43) + (96 / 2)) {
        *departure_time = 9 * 60 + 43;
        *arrival_time = 11 * 60 + 52;

    } else if (desired_time < ((11 * 60) + 19) + (88 / 2)) {
        *departure_time = 11 * 60 + 19;
        *arrival_time = 13 * 60 + 31;

    } else if (desired_time <= ((12 * 60) + 47) + (73 / 2)) {
        *departure_time = 12 * 60 + 47;
        *arrival_time = 15 * 60;

    } else if (desired_time <= ((14 * 60) + (105 / 2))) {
        *departure_time = 14 * 60;
        *arrival_time = 15 * 60 + 8;

    } else if (desired_time <= ((15 * 60) + 45) + (195 / 2)) {
        *departure_time = 15 * 60 + 45;
        *arrival_time = 17 * 60 + 55;

    } else if (desired_time <= ((19 * 60) + (165 / 2))) {
        *departure_time = 19 * 60;
        *arrival_time = 21 * 60 + 20;

    } else { 
        *departure_time = 21 * 60 + 45;
        *arrival_time = 23 * 60 + 58;
    }


}
