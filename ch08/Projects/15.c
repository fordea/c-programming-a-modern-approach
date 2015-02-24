#include <stdio.h>

int main(void)
{
    char ch, message[80] = {0};
    int i, message_length = 0, shift_amount;

    printf("Enter message to be encrypted: ");
    for (i = 0; (ch = getchar()) != '\n' && i < 80; i++) {
        message[i] = ch;
        message_length++;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    printf("Encrypted message: ");
    for (i = 0; i < message_length; i++) {

        if (message[i] >= 'A' && message[i] <= 'Z') {
            printf("%c", ((message[i] - 'A') + shift_amount) % 26 + 'A');
        }
        else if (message[i] >= 'a' && message[i] <= 'z') {
            printf("%c", ((message[i] - 'a') + shift_amount) % 26 + 'a');
        }
        else {
            printf("%c", message[i]);
        }

    }

    return 0;
}
