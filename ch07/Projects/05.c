#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int scrabble_value = 0;
    char ch;

    printf("Enter a word: ");

    while ((ch = getchar()) != '\n') {
        
        switch (toupper(ch)) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case '0': case 'R': case 'S': case 'T': case 'U':
                scrabble_value += 1;
                break;
            case 'D': case 'G':
                scrabble_value += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                scrabble_value += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                scrabble_value += 4;
                break;
            case 'K':
                scrabble_value += 5;
                break;
            case 'J': case 'X':
                scrabble_value += 8;
                break;
            case 'Q': case 'Z':
                scrabble_value += 10;
                break;
        }
    }
    printf("Scrabble value: %d", scrabble_value);
    
    return 0;
}
    
