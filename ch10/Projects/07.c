#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define DIGIT_SPACING 1
#define MAX_DIGITS_SPACE MAX_DIGITS * (DIGIT_WIDTH + DIGIT_SPACING)

void clear_digits_array(void);
void process_digit(int digit, int position);
void process_col_segment(int digit, int row, int col, int position);
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
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = position; col < position + DIGIT_WIDTH; col++) {
            process_col_segment(digit, row, col - position, col);
        }
    }
}

/* Process a single column segment in a digit */
void process_col_segment(int digit, int row, int col, int position)
{
    switch(row) {
    
        case 0: //Segment 0(col 1)
            if (col == 1 && segments[digit][0])
                digits[row][position] = '_';
            break;

        case 1: //Segments 5(col 0), 6(col 1), and 1(col 2)
            if (col == 0 && segments[digit][5])
                digits[row][position] = '|';
            else if (col == 1 && segments[digit][6])
                digits[row][position] = '_';
            else if (col == 2 && segments[digit][1])
                digits[row][position] = '|';
            break;

        case 2: //Segments 4(col 0), 3(col 1), and 2(col 2)
            if (col == 0 && segments[digit][4])
                digits[row][position] = '|';
            else if (col == 1 && segments[digit][3])
                digits[row][position] = '_';
            else if (col == 2 && segments[digit][2])
                digits[row][position] = '|';
            break;
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
