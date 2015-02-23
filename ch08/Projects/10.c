#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_FLIGHTS 8

int main(void)
{
    int flight, hour, minute, input_time;
    int closest_flight = 0, abs_difference, smallest_abs_difference = 1440;

    /* Populate departure times of flights*/
    int departure_times[8] = {8 * 60,
                              9 * 60 + 45,
                             11 * 60 + 19,
                             12 * 60 + 47,
                             14 * 60,
                             15 * 60 + 45,
                             19 * 60,
                             21 * 60 + 45};

    /* Populate arrival times of flights*/
    int arrival_times[8] = { 10 * 60 + 16,
                             11 * 60 + 52,
                             13 * 60 + 31,
                             15 * 60,
                             16 * 60 + 8,
                             17 * 60 + 55,
                             21 * 60 + 20,
                             23 * 60 + 58};

    printf("Please enter a time(hh:mm): ");
    scanf("%2d :%2d", &hour, &minute);
    input_time = (hour * 60) + minute;

    /* Calculate closest flight by comparing absolute values */
    for (flight = 0; flight < NUM_OF_FLIGHTS; flight++) {
        abs_difference = abs(input_time - departure_times[flight]);

        if (abs_difference < smallest_abs_difference) {
            smallest_abs_difference = abs_difference;
            closest_flight = flight;
        } else { /* Iterated past closest flight, so break. */
            break;
        }
    }

    printf("The closest flight departs at %.2d:%.2d, arriving at %.2d:%.2d.", 
            departure_times[closest_flight] / 60,
            departure_times[closest_flight] % 60,
            arrival_times[closest_flight] / 60,
            arrival_times[closest_flight] % 60);

    return 0;
}
