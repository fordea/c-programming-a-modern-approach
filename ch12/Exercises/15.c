#include <stdio.h>
#include <stdbool.h>

#define DAYS 7
#define HOURS 24

int main(void)
{
    const int temperatures[DAYS][HOURS] = {[1][3] = 20, [1][15] = 31}, *p;
    int day = 1;

    printf("Temperatures for day %d: \n", day);
    for (p = temperatures[day]; p < temperatures[day] + HOURS; p++) {
        printf("%d ", *p);
    }

    return 0;
}
