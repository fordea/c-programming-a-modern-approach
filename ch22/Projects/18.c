#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

int compare_nums(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0, numbers[MAX_NUMS];
    float median;
    if (argc != 2) {
        fprintf(stderr, "Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (!feof(fp) && i < MAX_NUMS) {
        fscanf(fp, " %d", &numbers[i++]);
    }

    qsort(numbers, i, sizeof(int), compare_nums);
    if (i % 2 == 0) {
        median = (numbers[(i-1)/2] + numbers[(i-1)/2+1]) / 2.0f;
    } else {
        median = (float)numbers[(i-1)/2];
    }
    printf("Median: %.1f\n", median);

    fclose(fp);
    return 0;
}

int compare_nums(const void *p1, const void *p2)
{
    return *((int *)p1) - *((int *)p2);
}
