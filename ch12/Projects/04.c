#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 50

int read_message(char a[], int n);
void print_message(char a[], int n);
bool is_palindrome_subscript(char a[], int n);
bool is_palindrome_pointer(char a[], int n);

int main(void)
{
    char message[N];

    int length = read_message(message, N);
    printf("%spalindrome\n", is_palindrome_subscript(message, length) ? "" : "Not a ");
    printf("%spalindrome", is_palindrome_pointer(message, length) ? "" : "Not a ");

    return 0;
}

int read_message(char a[], int n)
{
    char ch;
    int i = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (tolower(ch) >= 'a' && toupper(ch) <= 'z') {
            a[i] = tolower(ch);
            i++;
        }
    }

    return i;

}

bool is_palindrome_subscript(char a[], int n)
{
    int i, start = 0, end = n - 1;
    while (start < end) {
        if (a[start++] != a[end--])
            return false;
    }
    return true;
}

bool is_palindrome_pointer(char a[], int n)
{
    char *ptr_start = a, *ptr_end = a + n - 1;
    while (ptr_start < ptr_end) {
        if (*ptr_start++ != *ptr_end--)
            return false;
    }

    return true;
}
