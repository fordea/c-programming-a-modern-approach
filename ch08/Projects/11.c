#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, phone_number[15] = {0};
    int i, num_length = 0;
    printf("Enter phone number: ");

    for (i = 0; (ch = getchar()) != '\n' && i < 15; i++) {

        switch (toupper(ch)) {
            case 'A': case 'B': case 'C':   phone_number[i] = '2';
                                            break;
            case 'D': case 'E': case 'F':   phone_number[i] = '3';
                                            break;
            case 'G': case 'H': case 'I':   phone_number[i] = '4';
                                            break;
            case 'J': case 'K': case 'L':   phone_number[i] = '5';
                                            break;
            case 'M': case 'N': case 'O':   phone_number[i] = '6';
                                            break;
            case 'P': case 'R': case 'S':   phone_number[i] = '7';
                                            break;
            case 'T': case 'U': case 'V':   phone_number[i] = '8';
                                            break;
            case 'W': case 'X': case 'Y':   phone_number[i] = '9';
                                            break;
                                 default:   phone_number[i] = ch;
                                            break; 
        }
        num_length++;
    }

    printf("In numeric form: ");
    for (i = 0; i < num_length; i++)
        printf("%c", phone_number[i]);

    return 0;
}
