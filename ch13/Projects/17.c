#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define N 50

bool is_palindrome(const char *message);

int main(void)
{
    char message[N+1];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin); 
    if (message[strlen(message)-1] == '\n') {
        message[strlen(message)-1] = '\0';
    }
    printf("%spalindrome", is_palindrome(message) ? "" : "Not a ");
    return 0;
}

bool is_palindrome(const char *message)
{
    const char *left = message;
    while (*message) {
        message++;
    }
    const char *right = --message;

    for (; left < right; left++, right--) {
        if (!(*left == *right))
            return false;
    }
    return true;
}
