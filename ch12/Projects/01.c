#include <stdio.h>

#define N 50

int read_message(char a[], int n);
void print_message(char a[], int n);
void print_message_reverse_subscript(char a[], int n);
void print_message_reverse_pointer(char a[], char *a_last);

int main(void)
{
    char message[N];

    int message_length = read_message(message, N);
    print_message(message, message_length);
    print_message_reverse_subscript(message, message_length);
    print_message_reverse_pointer(message, &message[message_length-1]);

    return 0;
}

int read_message(char a[], int n)
{
    char ch;
    int i;
    printf("Enter a message: ");
    for (i = 0; (ch = getchar()) != EOF && ch != '\n'; i++)
        a[i] = ch;

    return i;

}

void print_message(char a[], int n)
{
    char *p;

    printf("Message: ");
    for (p = a; p < a + n; p++)
        printf("%c", *p);
    printf("\n");
}

void print_message_reverse_subscript(char a[], int n)
{
    int i;
    printf("Message in reverse using array subscripting: ");
    for (i = n - 1; i >= 0; i--)
        printf("%c", a[i]);
    printf("\n");
}

void print_message_reverse_pointer(char a[], char *a_last)
{
    char *p = a_last;

    printf("Message in reverse using a pointer to array elements: ");
    while (p >= &a[0])
        printf("%c", *p--);
    printf("\n");

}


