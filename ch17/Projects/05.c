#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int compare_words(const void *w1, const void *w2);

int main(void)
{
    char **words;
    char *word;
    int i = 0, num_words = 0;

    /* Allocate enough space for a single char pointer in words array */
    if ((words = malloc (sizeof(char *))) == NULL) {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0, num_words = 0 ; ; i++, num_words++) {

        /* Allocate enough space for a 20 char word */
        if ((word = malloc(MAX_WORD_LEN + 1)) == NULL) {
            printf("Error, malloc failed.\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter a word: ");
        fgets(word, MAX_WORD_LEN + 1, stdin);
        word[strlen(word) - 1] = '\0'; /* Remove new line char */

        if (word[0] == '\0') /* Break when empty input */
            break;

        *(words + i) = word;

        /* Increase the size of words to accomodate one more char * pointer */
        words = realloc(words, sizeof(char *) * (num_words + 2));
    }
    qsort(words, num_words, sizeof(char *), compare_words);

    printf("\nWords sorted\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", *(words + i));
    }
}

int compare_words(const void *w1, const void *w2)
{
    return strcmp( *(char **)w1, *(char **)w2 );
}
