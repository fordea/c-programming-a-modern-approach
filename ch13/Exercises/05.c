#include <stdio.h>
#include <ctype.h>

void capitalize_a(char str[]);
void capitalize_b(char *str);
void print_str(char *str);

int main(void)
{
    char str[10] = "j9.d,c34p\0";
    printf("Original String: ");
    print_str(str);

    capitalize_b(str);
    printf("Capitalized String: ");
    print_str(str);

    return 0;
}

void capitalize_a(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i++]);
    }
}

void capitalize_b(char *str)
{
    char *p;
    for (p = str; *p; p++) {
        *p = toupper(*p);
    }
}

void print_str(char *str)
{
    char *p;
    for (p = str; *p; p++)
        printf("%c", *p);
    printf("\n");
}

