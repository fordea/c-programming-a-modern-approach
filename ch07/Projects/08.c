#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute, mins_since_midnight, offset;
    char ch;
    printf("Please enter a 12 hour time: ");
    scanf("%2d :%2d %c", &hour, &minute, &ch);

    /* Create an offset to add to the hour if time is PM */
    offset = (toupper(ch) == 'P' ? 12 : 0);

    /* Handle two cases for 12 AM/PM
     * If hour input was 12, and offset is 12(PM), set hour to 0 so we can add offset 12
     * If hour input was 12, and offset is 0(AM), set hour to 0 so we can add offset 0 */
    hour = (hour == 12 ? 0 : hour);

    printf("Time in 24 hour format: %.2d:%.2d\n", hour + offset, minute);
    mins_since_midnight = ((offset + hour) * 60) + minute;

    /*Format for closest departure calculation:
     * if (input minutes since midnight < (departure hours * departure minutes)
     * + ((next departure time - current departure time) / 2) 
     *
     * For departure difference times that are odd, division is floored
     * In this case a comparison of <= is used.
     *
     * For departure difference times that are even, a halfway time is
     * equally close to both departures. In this case a comparsion of < is used
     * as I assume that the next flight is closer due to rounding up.
     */
    if (mins_since_midnight <= ((8 * 60) + (103 / 2)))
        printf("Closest departure time is 8:00 AM., arriving at 10:16 AM");
    else if (mins_since_midnight < ((9 * 60) + 43) + (96 / 2))
        printf("Closest departure time is 9:43 AM., arriving at 11:52 AM");
    else if (mins_since_midnight < ((11 * 60) + 19) + (88 / 2))
        printf("Closest departure time is 11:19 AM., arriving at 1:31 PM");
    else if (mins_since_midnight <= ((12 * 60) + 47) + (73 / 2))
        printf("Closest departure time is 12:47 PM., arriving at 3:00 PM");
    else if (mins_since_midnight <= ((14 * 60) + (105 / 2)))
        printf("Closest departure time is 2:00 PM., arriving at 4:08 PM");
    else if (mins_since_midnight <= ((15 * 60) + 45) + (195 / 2))
        printf("Closest departure time is 3:45 PM., arriving at 5:55 PM");
    else if (mins_since_midnight <= ((19 * 60) + (165 / 2)))
        printf("Closest departure time is 7:00 PM., arriving at 9:20 PM");
    else 
        printf("Closest departure time is 9:45 PM., arriving at 11:58 PM");

    return 0;
}
