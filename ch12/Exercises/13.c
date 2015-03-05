#include <stdio.h>

#define N 20

int main(void)
{
    double ident[N][N];
    double *p = &ident[0][0];
    int zero_count = N - 1;

    for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++) {
        if (zero_count == N - 1) {
            *p = 1;
            zero_count = 0;
        } else {
            *p = 0;
            zero_count++;
        }
    }

    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%.0f ", ident[row][col]);
        }
        printf("\n");
    }

    return 0;
}
