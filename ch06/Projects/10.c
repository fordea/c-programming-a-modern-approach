#include <stdio.h>

int main(void)
{
    int d, m, y, ed, em, ey, count = 0;

    for (;;) {

        printf("Enter a date (mm/dd/yy) (0/0/0 to terminate): ");
        scanf("%d /%d /%d", &m, &d, &y);

        if (m == 0 && d == 0 && y == 0) { //terminate on 0/0/0
            break;
        }

        if (count == 0) { //initialize earliest variables on first input
            ed = d; em = m; ey = y;
            count++;
            continue;
        }

        if (y > ey) { //Later year
            continue;

        } else if (y < ey) { //Earlier year
            ed = d; em = m; ey = y;

        } else { //Same year

            if (m > em) { //Later month
                continue;

            } else if (m < em) { //Earlier month
                ed = d; em = m; ey = y;

            } else { //Same month

                if (d > ed) { //Later day
                    continue;

                } else { //Earlier or same day
                    ed = d; em = m; ey = y;

                }

            }
        }
    }
    printf("%.2d/%.2d/%.2d is the earliest date", em, ed, ey);

    return 0;
}
