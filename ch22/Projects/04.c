#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int count_characters(char *filename);
int count_words(char *filename);
int count_lines(char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: programname filename.\n");
        exit(EXIT_FAILURE);
    }

    printf("Characters in the file \"%s\": %d\n", argv[1], count_characters(argv[1]));
    printf("Words in the file \"%s\": %d\n", argv[1], count_words(argv[1]));
    printf("Lines in the file \"%s\": %d\n", argv[1], count_lines(argv[1]));
    return 0;
}

int count_characters(char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error, cannot open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (getc(fp) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

int count_words(char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error, cannot open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int ch, count = 0;
    bool in_word = false;
    while ((ch = getc(fp)) != EOF) {
        if (!isspace(ch)) {
            if (!in_word) {
                count++;
                in_word = true;
            }
        }
        else {
            in_word = false;
        }
    }
    fclose(fp);
    return count;
}

int count_lines(char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error, cannot open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int ch, count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            count++;
    }
    fclose(fp);
    return count;
}
