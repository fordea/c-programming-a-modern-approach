#include <stdio.h>
#include <stdlib.h>

#define HOUR 60
#define NUM_FLIGHTS (sizeof(flights) / sizeof(flights[0]))

int main(void)
{
    const struct {
        int departure_time;
        int arrival_time;
    } flights[] = {

    /*     Departures           Arrivals     */
        {      8 * HOUR,    10 * HOUR + 16},
        { 9 * HOUR + 43,    11 * HOUR + 52},
        {11 * HOUR + 19,    13 * HOUR + 31},
        {12 * HOUR + 47,         15 * HOUR},
        {     14 * HOUR,    16 * HOUR +  8},
        {15 * HOUR + 45,    17 * HOUR + 55},
        {     19 * HOUR,    21 * HOUR + 20},
        {21 * HOUR + 45,    23 * HOUR + 58},
    };

    int hour, minute, input_time;
    printf("Please enter a time(hh:mm): ");
    scanf("%2d :%2d", &hour, &minute);

    input_time = (hour * HOUR) + minute;

    int prev_f, curr_f;

    for (prev_f = 0, curr_f = 1; curr_f < NUM_FLIGHTS; prev_f++, curr_f++)
        if ((abs(input_time - flights[curr_f].departure_time)) >=
            (abs(input_time - flights[prev_f].departure_time))) 
            break;

    printf("Closest Flight\nDeparts: %.2d:%.2d  Arrives: %.2d:%.2d\n",
            flights[prev_f].departure_time / HOUR,
            flights[prev_f].departure_time % HOUR,
            flights[prev_f].arrival_time / HOUR,
            flights[prev_f].arrival_time % HOUR);

    return 0;
}
