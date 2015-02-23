#include <stdio.h>

int main(void)
{
    char ch, sentence[200] = {0}, terminating_char = '?';
    int i, j, sentence_length = 0, current_word_length = 0;

    /* Populate sentence array until terminating character found */
    for (i = 0; (ch = getchar()) != '\n' && i < 200; i++) {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_char = ch;
            break;
        } else {
            sentence[i] = ch; 
            sentence_length++;
        }
    }

    /* Iterate backwards through sentence array */
    for (i = sentence_length - 1; i >= 0; i--) {

        /* If we find a space, or we are at the start of the sentence
         * we've found a new word */
        if (sentence[i] == ' ' || i == 0) {

            /* Special case when we are at the start of the sentence,
             * normally we iterate from i+1...word length to skip the white space, but
             * the start of the sentence will have no preceding white space */
            if (i == 0) { 
                i--;
            }

            /* Iterate forwards over the word we found and print */
            for (j = i + 1; j <= i + current_word_length + 1; j++)
                printf("%c", sentence[j]);

            current_word_length = 0;
        } else {
            current_word_length++;
        }
    }
    printf("%c", terminating_char);

    return 0;
}
