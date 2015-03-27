#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int compare_words(const void *w1, const void *w2);
void *my_malloc(char *p, int bytes);
void sort_and_print(char **pp, int n);

int main(void)
{
    char **words, *word;
    int i, size = 1, num_words = 0;

    words = my_malloc(*words, sizeof(char *));

    for (i = 0; ;i++) {

        word = my_malloc(word, MAX_WORD_LEN + 1);
        printf("Enter a word: ");
        fgets(word, MAX_WORD_LEN + 1, stdin);
        if (word[strlen(word) - 1] == '\n')
            word[strlen(word) - 1] = '\0'; /* Remove new line char */

        if (word[0] == '\0')
            break;

        *(words + i) = word;
        num_words++;

        if (size == num_words)
            words = realloc(words, sizeof(char *) * (size *= 2));
    }

    sort_and_print(words, num_words);
}

void *my_malloc(char *p, int bytes)
{
    if ((p = malloc(bytes)) == NULL) {
        printf("Error, malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

void sort_and_print(char **pp, int n)
{
    qsort(pp, n, sizeof(char *), compare_words);
    printf("\nWords sorted\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%s ", *(pp + i));
    }
    printf("\n");
}

int compare_words(const void *w1, const void *w2)
{
    return strcmp( *(char **)w1, *(char **)w2 );
}
