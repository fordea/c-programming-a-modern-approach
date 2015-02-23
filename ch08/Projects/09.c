#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_ROWS 10
#define NUM_COLS 10
#define EMPTY_CELL '.'

#define LEFT 0
#define DOWN 1
#define UP 2
#define RIGHT 3

int main(void)
{
    char grid[NUM_ROWS][NUM_COLS] = {}, letter;
    int i, row, col, potential_moves_count, potential_move;
    bool potential_moves[4], move_performed;

    srand((unsigned) time(NULL));

    /* populate the grid with '.' */
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            grid[row][col] = '.';
        }
    }

    /* Perform alphabet trail through grid cells */
    row = 0; col = 0;
    for (letter = 'A'; letter <= 'Z'; letter++) {

        grid[row][col] = letter;

        /* Reset potential_moves array */
        for (i = 0; i <= 3; potential_moves[i] = 0, i++)

        /* Find all potential moves from current cell */
        potential_moves_count = 0;
        if (col-1 >= 0 && grid[row][col-1] == EMPTY_CELL) {
            potential_moves[LEFT] = true;
            potential_moves_count++;
        }
        if (row+1 < NUM_ROWS && grid[row+1][col] == EMPTY_CELL) {
            potential_moves[DOWN] = true;
            potential_moves_count++;
        }
        if (row-1 >= 0 && grid[row-1][col] == EMPTY_CELL) {
            potential_moves[UP] = true;
            potential_moves_count++;
        }
        if (col+1 < NUM_COLS && grid[row][col+1] == EMPTY_CELL) {
            potential_moves[RIGHT] = true;
            potential_moves_count++;
        }

        /* Break if no moves are possible from current cell */
        if (potential_moves_count == 0)
            break;

        /* Generate random moves until one matches a potential move, then perform 
         * move */
        move_performed = 0;
        do {
            potential_move = rand() % 4;

            switch (potential_move) {
                case LEFT:
                    if (potential_moves[LEFT] == true) {
                        col--;
                        move_performed = 1;
                    }
                    break;
                case DOWN:
                    if (potential_moves[DOWN] == true) {
                        row++;
                        move_performed = 1;
                    }
                    break;
                case UP:
                    if (potential_moves[UP] == true) {
                        row--;
                        move_performed = 1;
                    }
                    break;
                case RIGHT:
                    if (potential_moves[RIGHT] == true) {
                        col++;
                        move_performed = 1;
                    }
                    break;
            }

        } while (!move_performed);
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
