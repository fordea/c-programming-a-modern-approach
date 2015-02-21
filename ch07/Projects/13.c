#include <stdio.h>
#include <ctype.h>

int main(void)
{
    float character_count = 0.0f, word_count = 0.0f;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {

        if (ch == ' ') { //assume one space per word
            word_count++;
            continue;
        }

        character_count++;
    }
    word_count += 1; //last word isn't counted due to break on \n, so increment by one.
    printf("Average word length: %.1f", character_count / word_count);

    return 0;
}


