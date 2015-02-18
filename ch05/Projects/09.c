#include <stdio.h>

#define EARLIER -1
#define SAME 0
#define LATER 1

int main(void)
{
    int d1_day, d1_month, d1_year, d2_day, d2_month, d2_year;
    int date1;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &d1_month, &d1_day, &d1_year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &d2_month, &d2_day, &d2_year);

    if (d1_year > d2_year) { //Later Year
        date1 = LATER;

    } else if (d1_year < d2_year) { //Earlier Year
        date1 = EARLIER; 

    }
    else { //Same Year
        if (d1_month > d2_month) { //Later Month
            date1 = LATER;

        } else if (d1_month < d2_month) { //Earlier Month
            date1 = EARLIER;

        } else { //Same Month
              if (d1_day > d2_day) { //Later Day
                  date1 = LATER;

              } else if (d1_day < d2_day) { //Earlier Day
                  date1 = EARLIER;

              } else { //Same Day
                  date1 = SAME;
              }       
          }
    }

    switch (date1) {
        case -1: printf("%d/%d/%d is earlier than %d/%d/%d",
                 d1_month, d1_day, d1_year, d2_month, d2_day, d2_year);
                 break;
        case 1:  printf("%d/%d/%d is earlier than %d/%d/%d",
                 d2_month, d2_day, d2_year, d1_month, d1_day, d1_year);
                 break;
        case 0:  printf("%d/%d/%d is the same as %d/%d/%d",
                 d2_month, d2_day, d2_year, d1_month, d1_day, d1_year);
                 break;
    }   

    return 0;
}
