#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *word_to_binary_str(int byte);
void print_characteristic_masks(void);
void print_char_characteristics(char c);

int main(void)
{
    print_characteristic_masks();
    print_char_characteristics('A');
    print_char_characteristics('Z');
    print_char_characteristics('7');
}


char *word_to_binary_str(int byte)
{
    static char bit_string[18];
    bit_string[0] = '\0';

    int mask;
    for (mask = 0x8000; mask > 0; mask >>= 1) {
        if (mask & 0x80)
            strcat(bit_string, " ");
        /* Check if the mask bit is set */
        strcat(bit_string, byte & mask ? "1" : "0");
    }

    return bit_string;
}

void print_characteristic_masks(void)
{
    printf("\nCharacteristic Masks:\n");
    printf("Upper: %s\n", word_to_binary_str(_ISupper));
    printf("Lower: %s\n", word_to_binary_str(_ISlower));
    printf("Alpha: %s\n", word_to_binary_str(_ISalpha));
    printf("Digit: %s\n", word_to_binary_str(_ISdigit));
    printf("xDigt: %s\n", word_to_binary_str(_ISxdigit));
    printf("Space: %s\n", word_to_binary_str(_ISspace));
    printf("Print: %s\n", word_to_binary_str(_ISprint));
    printf("Graph: %s\n", word_to_binary_str(_ISgraph));
    printf("Blank: %s\n", word_to_binary_str(_ISblank));
    printf("Cntrl: %s\n", word_to_binary_str(_IScntrl));
    printf("Punct: %s\n", word_to_binary_str(_ISpunct));
    printf("Alnum: %s\n", word_to_binary_str(_ISalnum));
}

void print_char_characteristics(char c)
{
    printf("\nCharacter '%c'\n", c);
    printf("Upper: %s - %d\n", word_to_binary_str(isupper(c)), isupper(c));
    printf("Lower: %s - %d\n", word_to_binary_str(islower(c)), islower(c));
    printf("Alpha: %s - %d\n", word_to_binary_str(isalpha(c)), isalpha(c));
    printf("Digit: %s - %d\n", word_to_binary_str(isdigit(c)), isdigit(c));
    printf("xDigt: %s - %d\n", word_to_binary_str(isxdigit(c)), isxdigit(c));
    printf("Space: %s - %d\n", word_to_binary_str(isspace(c)), isspace(c));
    printf("Print: %s - %d\n", word_to_binary_str(isprint(c)), isprint(c));
    printf("Graph: %s - %d\n", word_to_binary_str(isgraph(c)), isgraph(c));
    printf("Blank: %s - %d\n", word_to_binary_str(isblank(c)), isblank(c));
    printf("Cntrl: %s - %d\n", word_to_binary_str(iscntrl(c)), iscntrl(c));
    printf("Punct: %s - %d\n", word_to_binary_str(ispunct(c)), ispunct(c));
    printf("Alnum: %s - %d\n", word_to_binary_str(isalnum(c)), isalnum(c));
}
