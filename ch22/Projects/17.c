#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFSIZE 1024
#define ACODE 3
#define EXCH 3
#define SUBSCR 4

struct phone_number {
    char area_code[4];
    char exchange[4];
    char subscriber_num[5];
} pnum;

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZE], *ch;
    int i, line = 1;
    bool complete;

    while (fgets(buffer, BUFSIZE, fp) != NULL) {
        complete= false;
        for (i = 0, ch = buffer; i < ACODE && *ch; ++ch) {
            if (isdigit(*ch))
                pnum.area_code[i++] = *ch;
        }
        pnum.area_code[i] = '\0';
        for (i = 0; i < EXCH && *ch; ++ch) {
            if (isdigit(*ch))
                pnum.exchange[i++] = *ch;
        }
        pnum.exchange[i] = '\0';
        for (i = 0; i < SUBSCR && *ch; ++ch) {
            if (isdigit(*ch))
                pnum.subscriber_num[i++] = *ch;
            if (i == SUBSCR)
                complete = true;
        }
        pnum.subscriber_num[i] = '\0';
        if (complete)
            printf("(%s) %s-%s\n", pnum.area_code, pnum.exchange, pnum.subscriber_num);
        else
            fprintf(stderr, "Cannot process line %d, must have at least 10 digits.\n", line);
        ++line;
    }
    fclose(fp);
    return 0;
}
