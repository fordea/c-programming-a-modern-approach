#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute, offset;
    char ampm;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hour, &minute, &ampm);

    offset = (toupper(ampm) == 'P' ? 12 : 0);
    hour = (hour == 12 ? 0 : hour);

    printf("Equivalent 24-hour time: %.2d:%.2d", hour + offset, minute);

    return 0;
}

