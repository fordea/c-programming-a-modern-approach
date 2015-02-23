#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define EMPTY '.'
int main(void)
{
    char grid[ROWS][COLS] = {}, letter;
    int row, col;
    typedef int bool;
    bool performed_move;

    srand((unsigned) time(NULL));

    /* populate the grid with '.' */
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            grid[row][col] = '.';
        }
    }

    /* Perform alphabet trail through the grid */
    row = 0; col = 0;
    for (letter = 'A'; letter <= 'Z'; letter++) {

        grid[row][col] = (char) letter;

        /* Terminate if no more moves possible  */
        if (  (!(col-1 >= 0 && grid[row][col-1] == EMPTY))   //left not possible
           && (!(row+1 < ROWS && grid[row+1][col] == EMPTY)) //down not possible
           && (!(row-1 >= 0 && grid[row-1][col] == EMPTY))   //up not possible
           && (!(col+1 < COLS && grid[row][col+1] == EMPTY)) //right not possible 
           ) { printf("No moves possible\n"); break; }

        /* At least one move must be possible, so find random move */
        performed_move = 0;
        for (;;) {

            switch (rand() % 4) {
                case 0: // Left
                    if (col - 1 >= 0 && grid[row][col-1] == EMPTY) {
                        col--;
                        performed_move = 1;
                    }
                    break;
                case 1: // Down
                    if (row + 1 < ROWS && grid[row+1][col] == EMPTY) {
                        row++;
                        performed_move = 1;
                    }
                    break;
                case 2: // Up
                    if (row - 1 >= 0 && grid[row-1][col] == EMPTY) {
                        row--;
                        performed_move = 1;
                    }
                    break;
                case 3: // Right
                    if (col + 1 < COLS && grid[row][col+1] == EMPTY) {
                        col++;
                        performed_move = 1;
                    }
                    break;
            }
            if (performed_move)
                break;
        }
    }
             
    /* Print the final grid state */
    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            printf("%2c", grid[row][col]);
        }
        printf("\n");
    }

    return 0;
}
