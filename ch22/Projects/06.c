#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BYTES 10
typedef unsigned char BYTE;

void print_table_head(void);
void printbytes(BYTE a[], int bytes_read, int max_bytes);
void printchars(BYTE a[], int bytes_read);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2) {
        printf("Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Error, cannot open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    print_table_head();
    BYTE b[MAX_BYTES];
    int offset = 0;
    int bytes_read;
    while ((bytes_read = fread(b, sizeof(BYTE), MAX_BYTES, fp)) > 0) {
        printf("%6d  ", offset);
        printbytes(b, bytes_read, MAX_BYTES);
        printchars(b, bytes_read);
        offset += MAX_BYTES;
    }
    fclose(fp);
    return 0;
}

void print_table_head(void)
{
    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");
}

void printbytes(BYTE a[], int bytes_read, int max_bytes)
{
    for (int i = 0; i < max_bytes; ++i) {
        if (i >= bytes_read)
            printf("   ");
        else
            printf("%-3.2X", a[i]);
    }
    printf(" ");
}

void printchars(BYTE a[], int bytes_read)
{
    for (int i = 0; i < bytes_read; ++i) {
        printf("%c", isprint(a[i]) ? a[i] : '.');
    }
    printf("\n");
}
