#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *duplicate(char * str)
{
    char *duped_str;

    if ((duped_str = malloc(strlen(str) + 1)) == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    strcpy(duped_str, str);
    return duped_str;
}

int main(void)
{
    char *str = "testing.";
    char *str2 = duplicate(str);

    printf("Original String: %s\n", str);
    printf("Duplicated String: %s\n", str2);
}
