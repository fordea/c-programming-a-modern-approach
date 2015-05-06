#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

void merge_part_files(const char *infile1, const char *infile2,
        const char *outfile);
int compare_parts(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: programname infile1 infile2 outfile.\n");
        exit(EXIT_FAILURE);
    }
    merge_part_files(argv[1], argv[2], argv[3]);
    return 0;
}

void merge_part_files(const char *infile1, const char *infile2,
        const char *outfile)
{
    FILE *fpin1;
    FILE *fpin2;
    FILE *fpout;

    if ((fpin1 = fopen(infile1, "rb")) == NULL) {
        printf("Error, cannot open input file: %s.\n", infile1);
        exit(EXIT_FAILURE);
    }
    if ((fpin2 = fopen(infile2, "rb")) == NULL) {
        printf("Error, cannot open input file: %s.\n", infile2);
        exit(EXIT_FAILURE);
    }
    if ((fpout = fopen(outfile, "wb")) == NULL) {
        printf("Error, cannot create output file: %s.\n", outfile);
        exit(EXIT_FAILURE);
    }

    struct part part1, part2;
    short p1, p2;
    p1 = fread(&part1, sizeof(struct part), 1, fpin1);
    p2 = fread(&part2, sizeof(struct part), 1, fpin2);
    while (p1 == 1 && p2 == 1) {
        if (part1.number < part2.number) {
            fwrite(&part1, sizeof(struct part), 1, fpout);
            p1 = fread(&part1, sizeof(struct part), 1, fpin1);
        }
        else if (part1.number > part2.number) {
            fwrite(&part2, sizeof(struct part), 1, fpout);
            p2 = fread(&part2, sizeof(struct part), 1, fpin2);
        }
        else { /* Identical Part Numbers */
            if (strcmp(part1.name, part2.name) == 0) {
                fprintf(stderr, "Error, Part %d has different names: \
                    \"%s\" and \"%s\".\n", part1.number, part1.name, part2.name);
            }
            part1.on_hand += part2.on_hand;
            fwrite(&part1, sizeof(struct part), 1, fpout);
            p1 = fread(&part1, sizeof(struct part), 1, fpin1);
            p2 = fread(&part2, sizeof(struct part), 1, fpin2);
        }
    }

    while (p1 == 1) {
        fwrite(&part1, sizeof(struct part), 1, fpout);
        p1 = fread(&part1, sizeof(struct part), 1, fpin1);
    }
    while (p2 == 1) {
        fwrite(&part2, sizeof(struct part), 1, fpout);
        p2 = fread(&part2, sizeof(struct part), 1, fpin2);
    }

    fclose(fpin1);
    fclose(fpin2);
    fclose(fpout);
}
