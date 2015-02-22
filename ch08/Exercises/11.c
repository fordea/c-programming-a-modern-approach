#include <stdio.h>

int main (void)
{
    char checker_board[8][8] = {0};

    int row, col;
    for (row = 0; row < 8; row++) {

        for (col = 0; col < 8; col++) {
            checker_board[row][col] = (row + col) % 2 == 0 ? 'B' : 'R';
            printf("%c, ", checker_board[row][col]);
        }
        printf("\n");
    }

    return 0;
}
