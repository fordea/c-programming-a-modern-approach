#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[MAX_LEN+1];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Average word length: %.1f", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    const char *p = sentence;
    int char_count = 0, word_count = 0;

    while (*p == ' ') //skip leading whitespace
        p++;

    for (; *p && *p != '\n'; p++) {
        if (*p == ' ') {
            if (*(p-1) != ' ')
                word_count++;
            continue;
        }
        if (*(p+1) == '\n')
            word_count++;

        char_count++;
    }
    printf("Char count: %d\n", char_count);
    printf("Word count: %d\n", word_count);
    
    return word_count != 0 ? ((double) char_count) /  word_count : 0;

}

