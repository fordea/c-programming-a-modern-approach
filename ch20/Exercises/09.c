#include <stdio.h>

int count_ones_v1(unsigned char ch);
int count_ones_v2(unsigned char ch);
int count_ones_v3(unsigned char ch);
int count_ones_recursive(unsigned char ch);
int count_ones_no_loop(unsigned char ch);

int main(void)
{
    unsigned char ch = 253;
    printf("%d\n", count_ones_v1(ch));
    printf("%d\n", count_ones_v2(ch));
    printf("%d\n", count_ones_v3(ch));
    printf("%d\n", count_ones_recursive(ch));
    printf("%d\n", count_ones_no_loop(ch));
}

/* Counts ones from least significant bit to most significant bit in O(8 bits) */
int count_ones_v1(unsigned char ch)
{
    short count;
    while (ch > 0) {
        if (ch & 1) {
            count++;
        }
        ch >>= 1;
    }
}

/* Counts ones from most significant bit to least significant bit in O(8 bits) */
int count_ones_v2(unsigned char ch)
{
    unsigned char mask;
    short count = 0;

    for (mask = 1 << 7; mask > 0; mask >>= 1) {
        if (ch & mask)
            count++;
    }

    return count;
}

/* Counts ones, eliminating least significant 1 bit in each iteration. O(number of 1 bits) */
int count_ones_v3(unsigned char ch)
{
    short count = 0;
    while (ch > 0) {
        count++;
        ch &= ch-1;
    }
    return count;
}

/* Counts ones, eliminating least significant 1 bit each recursive call. O(number of 1 bits) */
int count_ones_recursive(unsigned char ch) {
    if (ch == 0)
        return 0;
    return count_ones_recursive(ch & ch - 1) + 1;
}

/* Counts ones from most significant bit to least significant bit (no loop) O(8 bits) */
int count_ones_no_loop(unsigned char ch)
{
    return ((ch >> 7) & 1)
         + ((ch >> 6) & 1)
         + ((ch >> 5) & 1)
         + ((ch >> 4) & 1)
         + ((ch >> 3) & 1)
         + ((ch >> 2) & 1)
         + ((ch >> 1) & 1)
         + (ch & 1);
}
