#include <stdio.h>
#include <string.h>

#define N 50

void reverse(char *message);

int main(void)
{
    char message[N+1];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    reverse(message);
    printf("Reversed message: %s", message);

    return 0;
}

void reverse(char *message)
{
    char temp;
    char *left = message;
    while (*message) {
        message++;
    }
    char *right = --message; /* - ignore the '\0' char */

    for (; left < right; left++, right--) {
        temp = *left;
        *left = *right;
        *right = temp;
    }
}
