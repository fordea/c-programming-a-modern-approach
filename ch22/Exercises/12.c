#include <stdio.h>

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    int ch;
    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF)
            if (ch == '.')
                n++;
        fclose(fp);
    }
    return n;
}

int main(void) {
    printf("periods: %d\n", count_periods("testperiods"));
}
