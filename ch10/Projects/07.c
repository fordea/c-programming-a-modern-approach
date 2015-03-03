#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define DIGIT_SPACING 1

#define MAX_DIGITS_SPACE (MAX_DIGITS * (DIGIT_WIDTH + DIGIT_SPACING)) - DIGIT_SPACING
#define MAX_SEGMENTS 7

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/* Contains digit segments for all digits 0 through 9.
 * Segments are 'off' if 0, and 'on' if 1.
 * All digits can be represented using a maximum of 7 segments.
 *
 *     0
 *    ___ 
 * 5 |   | 1
 *   |_6_|
 * 4 |   | 2
 *   |___|
 *     3
 */
const int digit_segments[10][7] = {
/*Segment: 0  1  2  3  4  5  6  | Digit | */
          {1, 1, 1, 1, 1, 1, 0}, /* 0 */
          {0, 1, 1, 0, 0, 0, 0}, /* 1 */
          {1, 1, 0, 1, 1, 0, 1}, /* 2 */
          {1, 1, 1, 1, 0, 0, 1}, /* 3 */
          {0, 1, 1, 0, 0, 1, 1}, /* 4 */
          {1, 0, 1, 1, 0, 1, 1}, /* 5 */
          {1, 0, 1, 1, 1, 1, 1}, /* 6 */
          {1, 1, 1, 0, 0, 0, 0}, /* 7 */
          {1, 1, 1, 1, 1, 1, 1}, /* 8 */
          {1, 1, 1, 1, 0, 1, 1}  /* 9 */
};

/* Row, col positions of the 7 segments in a 3 by 3 grid 
 * positions 0,0 and 0,2 do not contain a segment 
 *
 *    012 
 *  0  _
 *  1 |_|
 *  2 |_| 
 */
const int segment_grid_pos[MAX_SEGMENTS][2] = {
/*  row  col | Segment | */
    {0,   1},  /* 0 */
    {1,   2},  /* 1 */
    {2,   2},  /* 2 */
    {2,   1},  /* 3 */
    {2,   0},  /* 4 */
    {1,   0},  /* 5 */
    {1,   1}   /* 6 */
};

char digits[DIGIT_HEIGHT][MAX_DIGITS_SPACE];

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    printf("Enter a number (up to 10 digits): ");
    while ((ch = getchar()) != '\n' && position < MAX_DIGITS_SPACE) {

        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += DIGIT_WIDTH + DIGIT_SPACING;
        }
    }
    print_digits_array();

}

/* Fill the digits array with empty spaces */
void clear_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            digits[row][col] = ' ';
    }
}

/* Construct a digit in the digits array at the starting col */
void process_digit(int digit, int starting_col)
{
    int segment, segment_row_pos, segment_col_pos;

    for (segment = 0; segment < MAX_SEGMENTS; segment++) {

        if (digit_segments[digit][segment]) {
            segment_row_pos = segment_grid_pos[segment][0];
            segment_col_pos = segment_grid_pos[segment][1] + starting_col;
            digits[segment_row_pos][segment_col_pos] = segment % 3 == 0 ? '_' : '|';
        }
    }
}

/* Print the digits array */
void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            printf("%c", digits[row][col]);

        printf("\n");
    }
}
