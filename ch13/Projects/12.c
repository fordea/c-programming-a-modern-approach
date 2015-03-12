#include <stdio.h>

#define MAX_WORD_COUNT 30
#define MAX_WORD_LENGTH 20

void print_sentence_reverse(char sentence[][MAX_WORD_LENGTH+1], int n, char term);

int main(void)
{
    char sentence[MAX_WORD_COUNT][MAX_WORD_LENGTH+1];
    char ch, terminating_char = '?';
    int row, col, word_count = 0;

    /* Populate sentence array with words until terminating character found */
    for (row = 0, col = 0; (ch = getchar()) != '\n'; col++) {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_char = ch;
            sentence[row][col] = '\0';
            break;
        } else if (ch == ' ') {
            sentence[row][col] = '\0';
            row++;
            col = -1;
            word_count++;
        } else {
            sentence[row][col] = ch; 
        }
    }

    print_sentence_reverse(sentence, word_count, terminating_char);

    return 0;
}

void print_sentence_reverse(char sentence[][MAX_WORD_LENGTH+1], int n, char term)
{
    int row, col;

    for (row = n; row >= 0; row--) {
        for (col = 0; sentence[row][col]; col++)
            printf("%c", sentence[row][col]);
        printf(" ");
    }
    printf("%c", term);
}
