#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_COUNT 30 
#define MAX_WORD_LENGTH 20 + 1

char (*read_sentence(char sentence[][MAX_WORD_LENGTH]))[MAX_WORD_LENGTH];
void print_sentence_reverse(char (*first_word)[MAX_WORD_LENGTH],
                            char (*last_word)[MAX_WORD_LENGTH]);

int main(void)
{
    char sentence[MAX_WORD_COUNT][MAX_WORD_LENGTH];

    printf("Enter sentence: (upto %d words): ", MAX_WORD_COUNT);
    print_sentence_reverse(sentence, read_sentence(sentence));

    return 0;
}

char (*read_sentence(char sentence[][MAX_WORD_LENGTH]))[MAX_WORD_LENGTH]
{
    int input_char, term_char = '.';
    char (*word_ptr)[MAX_WORD_LENGTH] = sentence, *char_ptr = word_ptr[0];
    bool char_inside_word = false;
    
    while ((input_char = getchar()) != '\n' && word_ptr < sentence + MAX_WORD_COUNT) {

        if (input_char == '.' || input_char == '?' || input_char == '!') {
            term_char = input_char;
            break;

        } else if (!isspace(input_char)) {
            char_inside_word = true;
            *char_ptr++ = input_char; 

        } else if (char_inside_word) {
            char_inside_word = false;
            *char_ptr = '\0';
            word_ptr++;
            char_ptr = word_ptr[0];
        }

    }

    /* If blank input then insert '\0' in first word */
    if (char_ptr == sentence[0]) {
        sentence[0][0] = '\0';
    }

    /* If the last word input was equal to the maximum number of words, decrement word
     * ptr by 1 otherwise word pointer is too far*/
    if (word_ptr == sentence + MAX_WORD_COUNT)
        word_ptr--;

    /* If input ended without a space, insert '\0' at end of last word */
    if (char_inside_word)
        *char_ptr = '\0';

    /* Insert terminating char at the end of the first word by finding '\0' in first word */
    for (char_ptr = sentence[0]; *char_ptr && char_ptr < sentence[0] + (MAX_WORD_LENGTH-1);
            char_ptr++); /* Empty loop body */
    *char_ptr++ = term_char;
    *char_ptr = '\0';

    return word_ptr;
}

void print_sentence_reverse(char (*first_word)[MAX_WORD_LENGTH],
                            char (*last_word)[MAX_WORD_LENGTH])
{
    char *char_ptr;
    while (last_word >= first_word) {
        for (char_ptr = last_word[0]; *char_ptr; char_ptr++)
            printf("%c", *char_ptr);
        last_word--;
        printf(" ");
    }
}
