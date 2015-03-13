#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN 50+1

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[LEN], word2[LEN];
    int ch, i;

    printf("Enter first word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < LEN; i++)
        word1[i] = toupper(ch);
    word1[i] = '\0';

    printf("Enter second word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < LEN; i++)
        word2[i] = toupper(ch);
    word2[i] = '\0';

    printf("Anagrams? %s", are_anagrams(word1, word2) ? "Yes" : "No");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int i, letter_count[26] = {0};

    while (*word1) {
        letter_count[*word1++ - 'A']++;
    }

    while (*word2) {
        letter_count[*word2++ - 'A']--;
    }

    for (i = 0; i < 26; i++)
        if (letter_count[i] != 0)
            return false;

    return true;
}
