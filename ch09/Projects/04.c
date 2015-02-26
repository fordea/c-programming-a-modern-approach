#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int counts1[26] = {0}, counts2[26] = {0};
    read_word(counts1);
    read_word(counts2);

    printf("The words are ");
    if (equal_array(counts1, counts2))
        printf("anagrams.");
    else
        printf("not anagrams.");

    return 0;
}

void read_word(int counts[26])
{
    int i;
    char ch;

    printf("Enter word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < 30; i++)
        counts[toupper(ch) - 'A']++;
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;
    bool equal = true;

    for (i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i]) {
            equal = false;
            break;
        }  
    }
    return equal;
}
