#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define DIGIT_SPACING 1
#define MAX_DIGITS_SPACE MAX_DIGITS * (DIGIT_WIDTH + DIGIT_SPACING)
#define TOTAL_SEGMENTS 7

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, /* 0 */
/* Row 0:       0     */     {0, 1, 1, 0, 0, 0, 0}, /* 1 */
/*             ---    */     {1, 1, 0, 1, 1, 0, 1}, /* 2 */
/*            |   |   */     {1, 1, 1, 1, 0, 0, 1}, /* 3 */
/* Row 1:   5 | 6 | 1 */     {0, 1, 1, 0, 0, 1, 1}, /* 4 */
/*             ---    */     {1, 0, 1, 1, 0, 1, 1}, /* 5 */
/*            |   |   */     {1, 0, 1, 1, 1, 1, 1}, /* 6 */
/* Row 2:   4 | 3 | 2 */     {1, 1, 1, 0, 0, 0, 0}, /* 7 */
/*             ---    */     {1, 1, 1, 1, 1, 1, 1}, /* 8 */
/*                    */     {1, 1, 1, 1, 0, 1, 1}};/* 9 */

/* row, col position of the seven segments in a 3 by 3 grid 
 * positions 0,0 and 0,2 do not contain a segment */
const int segment_rowcol[TOTAL_SEGMENTS][2] = { {0, 1},   /* 0 */
                                                {1, 2},   /* 1 */
                                                {2, 2},   /* 2 */
                                                {2, 1},   /* 3 */
                                                {2, 0},   /* 4 */
                                                {1, 0},   /* 5 */
                                                {1, 1} }; /* 6 */

char digits[DIGIT_HEIGHT][MAX_DIGITS_SPACE];

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    printf("Enter a number (up to 10 digits): ");
    while ((ch = getchar()) != '\n' && position <= MAX_DIGITS_SPACE) {

        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += DIGIT_WIDTH + DIGIT_SPACING;
        }
    }
    print_digits_array();

}

void clear_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            digits[row][col] = ' ';
    }
}

/* Process a single digit */
void process_digit(int digit, int position)
{
    int segment, segment_row_pos, segment_col_pos;

    for (segment = 0; segment < TOTAL_SEGMENTS; segment++) {

        if (segments[digit][segment]) {
            segment_row_pos = segment_rowcol[segment][0];
            segment_col_pos = position + segment_rowcol[segment][1];

            if (segment % 3 == 0) //segments divisible by 3 are always '_'
                digits[segment_row_pos][segment_col_pos] = '_';
            else
                digits[segment_row_pos][segment_col_pos] = '|';
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
