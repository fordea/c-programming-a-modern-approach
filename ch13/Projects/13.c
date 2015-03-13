#include <stdio.h>

#define LEN 80 + 1

void encrypt(char *message, int shift);

int main(void)
{
    char message[LEN];
    int shift_amount;

    printf("Enter message to be encrypted: ");
    fgets(message, LEN, stdin);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);
    encrypt(message, shift_amount);

    return 0;
}

void encrypt(char *message, int shift)
{
    char *p;

    printf("Encrypted message: ");
    for (p = message; *p; p++) {

        if (*p >= 'A' && *p <= 'Z')
            printf("%c", ((*p - 'A') + shift) % 26 + 'A');
        else if (*p >= 'a' && *p <= 'z')
            printf("%c", ((*p - 'a') + shift) % 26 + 'a');
        else
            printf("%c", *p);
    }

}
