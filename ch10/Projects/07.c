#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, /* 0 */
/*     0     */              {0, 1, 1, 0, 0, 0, 0}, /* 1 */
/*    ---    */              {1, 1, 0, 1, 1, 0, 1}, /* 2 */
/* 5 |   | 1 */              {1, 1, 1, 1, 0, 0, 1}, /* 3 */
/*   | 6 |   */              {0, 1, 1, 0, 0, 1, 1}, /* 4 */
/*    ---    */              {1, 0, 1, 1, 0, 1, 1}, /* 5 */
/* 4 |   | 2 */              {1, 0, 1, 1, 1, 1, 1}, /* 6 */
/*   | 3 |   */              {1, 1, 1, 0, 0, 0, 0}, /* 7 */
/*    ---    */              {1, 1, 1, 1, 1, 1, 1}, /* 8 */
/*           */              {1, 1, 1, 1, 0, 1, 1}};/* 9 */

char digits[3][MAX_DIGITS*4];

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    printf("Enter a number (up to 10 digits): ");
    while ((ch = getchar()) != '\n' && position <= MAX_DIGITS * 4) {

        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += DIGIT_WIDTH + 1;
        }
    }
    print_digits_array();

}

void clear_digits_array(void)
{
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < MAX_DIGITS * DIGIT_WIDTH; col++) 
            digits[row][col] = ' ';
    }
}

void process_digit(int digit, int position)
{
    //iterate through 3x3 grid for digit segments
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = position; col < position + DIGIT_WIDTH; col++)

            if (row == 0) { //top row (segment 0)
                if (col == position + 1 && segments[digit][0] == 1) {
                    digits[row][col] = '_';
                }
            }
            else if (row == 1) { //second row (segments 5 6 1)
                if (col == position && segments[digit][5] == 1)
                    digits[row][col] = '|';
                else if (col == position + 1 && segments[digit][6] == 1)
                    digits[row][col] = '_';
                else if (col == position + 2 && segments[digit][1] == 1)
                    digits[row][col] = '|';
            }
            else { //third row (segments 4 3 2)
                if (col == position && segments[digit][4] == 1)
                    digits[row][col] = '|';
                else if (col == position + 1 && segments[digit][3] == 1)
                    digits[row][col] = '_';
                else if (col == position + 2 && segments[digit][2] == 1)
                    digits[row][col] = '|';
            }
    }
}

void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < MAX_DIGITS * 4; col++) 
            printf("%c", digits[row][col]);
        printf("\n");
    }
}
