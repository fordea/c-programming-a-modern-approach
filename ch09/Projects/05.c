#include <stdio.h>
#include <stdbool.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int n;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int magic_square[n][n];
    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);

    return 0;
}

/* Populate the magic square array */
void create_magic_square(int n, int magic_square[n][n])
{
    int i, row, col, next_row_pos, next_col_pos;

    /* Fill the magic square with zeroes */
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            magic_square[row][col] = 0;
    }

    /* Populate the magic square */
    i = 1, row = 0, col = n / 2;
    while (i <= n * n) {

        magic_square[row][col] = i;

        /* Get next row position */
        if (row == 0)
            next_row_pos = n - 1;
        else
            next_row_pos = row - 1;

        /* Get next col position */
        if (col == n - 1)
            next_col_pos = 0;
        else
            next_col_pos = col + 1;

        /* If the next magic square position is populated (not 0),
         * decrement the row by one. If it isn't then set the row
         * and the col to the next positions */
        if (magic_square[next_row_pos][next_col_pos] != 0) {
            row++;
        } else {
            row = next_row_pos;
            col = next_col_pos;
        }

        i++;
    }


}

/* Print the magic square */
void print_magic_square(int n, int magic_square[n][n])
{
    int row, col;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            printf("%5d", magic_square[row][col]);
        printf("\n");
    }
}
