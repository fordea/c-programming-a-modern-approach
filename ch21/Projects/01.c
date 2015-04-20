#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void)
{
    printf("%ld\n", offsetof(struct s, a));
    printf("%ld\n", offsetof(struct s, b[0]));
    printf("%ld\n", offsetof(struct s, b[1]));
    printf("%ld\n", offsetof(struct s, c));

    /* List of "holes":
     * 3 byte hole after member a (offset of b[0] is 4)
     * No other holes present in struct s
     */
}
