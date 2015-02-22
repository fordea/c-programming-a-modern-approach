#include <stdio.h>

int main(void)
{
    int temperature_readings[30][24] = {{1234}, //some fluff data for tests
                                        {2345},
                                        {72834},
                                        {347},
                                        {12743},
                                        {87},
                                        {3248},
                                        {89743}};

    int day, hour;
    float month_average = 0.0f;

    for (day = 0; day < 30; day++) { //iterate through days
        float day_average = 0.0f;

        for (hour = 0; hour < 24; hour++) { //iterate through hours
            day_average += temperature_readings[day][hour];
        }

        day_average = (!day_average == 0.0f ? day_average /= 24 : day_average);
        printf("Average Temperature for day %d: %.2f\n", day + 1,day_average );
        month_average += day_average;
    }

    month_average = (!month_average == 0.0f ? month_average /= 30 : month_average);
    printf("Average monthly temperature: %.0f", month_average );

    return 0;
}
