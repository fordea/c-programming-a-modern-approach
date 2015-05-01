#include <stdio.h>

#define MAX_LINE_LEN 500

char *my_fgets(char *str, int n, FILE *stream);
int my_fputs(const char * restrict s, FILE * restrict stream);

int main(void)
{
    FILE *fp;
    char line[MAX_LINE_LEN + 1];
    if ((fp = fopen("testlines", "r")) != NULL) {
        my_fgets(line, sizeof(line), fp);
        fclose(fp);
    }
    printf("%s", line);
    int i = my_fputs("test", stdout);
    printf("\n%d\n", i);

}

char *my_fgets(char *str, int n, FILE *stream)
{
    int ch, chars_read = 0;

    while (chars_read < n - 1 && (ch = getc(stream)) != EOF) {
        str[chars_read++] = ch;
        if (ch == '\n')
            break;
    }
    if (chars_read == 0 || ferror(stream)) {
        return NULL;
    }
    str[chars_read] = '\0';
    return str;
}

int my_fputs(const char * restrict s, FILE * restrict stream)
{
    while (*s) {
        if (putc(*s++, stream) == EOF)
            return EOF;
    }
    return 0;
}
