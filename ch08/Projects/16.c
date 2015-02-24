#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int i, letter_count[26] = {0};
    char ch;
    bool is_anagram = true;

    printf("Enter first word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < 30; i++)
        letter_count[toupper(ch) - 'A']++;

    printf("Enter second word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < 30; i++)
        letter_count[toupper(ch) - 'A']--;


    for (i = 0; i < 26; i++) {
        if (letter_count[i] != 0) {
            is_anagram = false;
            break;
        }  
    }

    printf("The words are ");
    if (is_anagram)
        printf("anagrams.");
    else
        printf("not anagrams.");

    return 0;
}
