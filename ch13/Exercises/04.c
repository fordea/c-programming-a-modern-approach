#include <stdio.h>
#include <ctype.h>

int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);
void print_line(char str[]);

int main(void)
{
    char msg[20];
    printf("Enter a message: ");
    read_line_a(msg, 20);
    print_line(msg);
    return 0;
}

int read_line_a(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i == 0 && isspace(ch)); //do nothing

        else if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
}

int read_line_b(char str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar())) {
        if (i < n)
            str[i++] = ch;
    } 
    str[i] = '\0';
    return i;
}

int read_line_c(char str[], int n)
{
    int ch, i = 0;

    do {
        ch = getchar();
        if (i < n)
            str[i++] = ch;
    } while (ch != '\n');
    str[i] = '\0';
    return i;
}

int read_line_d(char str[], int n)
{
    int i, ch;

    for (i = 0; i < n - 1; i++) {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}

void print_line(char str[])
{
    char *p;

    for (p = str; *p != '\0'; p++)
        printf("%c", *p);
}

