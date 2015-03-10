#include <stdio.h>

void remove_filename(char *url);

int main(void)
{
    char url[] = "http://www.knking.com/index.html";
    printf("Whole URL: %s\n", url);
    remove_filename(url);
    printf("URL without file name: %s", url);
    return 0;
}

void remove_filename(char *url)
{
    while (*url++); /* Empty body */
    while (*url-- != '/'); /* Empty body */
    *++url = '\0';
}
