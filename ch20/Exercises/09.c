#include <stdio.h>

int count_ones(unsigned char ch);
int count_ones_no_loop(unsigned char ch);

int main(void)
{
    char ch = 'A';
    printf("%d\n", count_ones(ch));
}

int count_ones(unsigned char ch)
{
    unsigned char mask;
    short count = 0;

    for (mask = 1 << 7; mask > 0; mask >>= 1) {
        if (ch & mask)
            count++;
    }

    return count;
}

int count_ones_no_loop(unsigned char ch)
{
    unsigned char mask = 255;

}
