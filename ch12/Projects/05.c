#include <stdio.h>

int main(void)
{
    char ch, sentence[200] = {0}, terminating_char = '?';
    int i, j, sentence_length = 0, current_word_length = 0;
    char *p, *pw;

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
    for (p = sentence + sentence_length - 1; p >= sentence; p--) {

        /* If we find a space, or we are at the start of the sentence
         * we've found a new word */
        if (*p == ' ' || p == sentence) {

            /* Special case when we are at the start of the sentence,
             * normally we iterate from i+1...word length to skip the white space, but
             * the start of the sentence will have no preceding white space */
            if (p == sentence) { 
                p--;
            }

            /* Iterate forwards over the word we found and print */
            for (pw = p + 1; pw <= p + current_word_length + 1; pw++)
                printf("%c", *pw);

            current_word_length = 0;
        } else {
            current_word_length++;
        }
    }
    printf("%c", terminating_char);

    return 0;
}
