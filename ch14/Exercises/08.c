#include <stdio.h>

/* macro to stringize the values of the macros __LINE__ and __FILE__ */
#define STRINGIZE(x) #x

/* We need to expand __LINE__ and __FILE__ first to their values before stringizing them,
   otherwise STRINGIZE would only convert the macro names to string */
#define EXPAND_TO_STRING(x) STRINGIZE(x) 

/* We can now call EXPAND_TO_STRING on both __LINE__ and __FILE__ and join them to other strings */
#define LINE_FILE "Line " EXPAND_TO_STRING(__LINE__) " of file " EXPAND_TO_STRING(__FILE__)

int main(void)
{
    const char *str = LINE_FILE;
    printf("%s\n", str);
}
