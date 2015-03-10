#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool test_extension(const char *file_name, const char *extension);

int main(void)
{
    const char file_name[] = "memo.txt";
    const char extension[] = "TXT";
    printf("%s", test_extension(file_name, extension) ? "True" : "False");
    return 0;
}

bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name++ != '.');

    if (strlen(file_name) != strlen(extension))
        return false;

    while (*file_name)
        if (!toupper(*file_name++) == toupper(*extension++))
            return false;
    return true;
}
