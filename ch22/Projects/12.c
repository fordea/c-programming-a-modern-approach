#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[1024];
    FILE *fp;
    if (argc != 2) {
        fprintf(stderr, "Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", argv[1]);
    }

    int item_number, month, day, year;
    float unit_price;
    int line = 1;
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if ((sscanf(buffer, "%d,%f,%2d%*[-/]%2d%*[-/]%4d", &item_number,
                        &unit_price, &month, &day, &year)) != 5) {
            fprintf(stderr, "Error processing line %d, ignored.\n", line);
            ++line;
            continue;
        }
        printf("%d\t\t$%6.2f\t\t%.2d/%.2d/%.4d\n", item_number,
            unit_price, month, day, year);
        ++line;
    }
    return 0;
}
