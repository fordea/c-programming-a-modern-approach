#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 500

int line_length(const char *filename, int n);
int count_length(const char *s);

int main(void)
{
    int line = 3;
    printf("Line %d length: %d\n", line, line_length("testlines", line));
}

int line_length(const char *filename, int n)
{
    FILE *fp;
    char line[MAX_LINE_LEN + 1];
    if ((fp = fopen(filename, "r")) != NULL) {
        int line_num = 1;
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (line_num == n)
                return count_length(line);
            ++line_num;
        }
        fclose(fp);
    }
    return 0;

}

/* Counts the length of string s, ignoring new line chars */
int count_length(const char *s)
{
    int n = 0;
    while (*s++) {
        if (*s != '\n')
            ++n;
    }
    return n;
}
