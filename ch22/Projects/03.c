#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;

    if (argc < 2) {
        printf("Usage: programname filename(s).\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("Error, cannot open file: %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        else {
            while ((ch = getc(fp)) != EOF) {
                putchar(ch);
            }
            fclose(fp);
        }
    }
    return 0;
}
