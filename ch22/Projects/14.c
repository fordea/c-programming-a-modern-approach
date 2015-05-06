#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fpin, *fpout;
    char filename[FILENAME_MAX];
    int i, message_length = 0, shift_amount;

    printf("Enter name of file to be encrypted: ");
    scanf("%s", filename);
    if ((fpin = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    char *new_filename;
    new_filename = malloc(strlen(filename) + 5);
    strcpy(new_filename, filename);
    strcat(new_filename, ".enc");
    if ((fpout = fopen(new_filename, "w")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    free(new_filename);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    int ch;
    while ((ch = getc(fpin)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            putc(((ch - 'A') + shift_amount) % 26 + 'A', fpout);
        } else if (ch >= 'a' && ch <= 'z') {
            putc(((ch - 'a') + shift_amount) % 26 + 'a', fpout);
        } else {
            putc(ch, fpout);
        }
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
