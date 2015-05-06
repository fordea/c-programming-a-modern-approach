#include <stdio.h>

#define DATE_SIZE 10
int main(void)
{
    char date[DATE_SIZE + 1];
    int month, day, year;
    printf("Enter a date (mm-dd-yyyy or mm/dd/yyyy): ");
    fgets(date, DATE_SIZE, stdin);
    sscanf(date,"%d%*[-/]%d%*[-/]%d", &month, &day, &year);
    printf("Month: %d\nDay: %d\nYear: %d\n", month, day, year);
    return 0;
}
