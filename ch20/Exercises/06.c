#include <stdio.h>
#include <string.h>

unsigned short swap_bytes(unsigned short i);
unsigned short swap_bytes_condensed(unsigned short i);

int main(void)
{
    unsigned short value;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%4hx", &value);
    /* printf("Number with bytes swapped: %hx\n", swap_bytes(value)); */
    printf("Number with bytes swapped: %hx\n", swap_bytes_condensed(value));
}

unsigned short swap_bytes(unsigned short i)
{
    unsigned short b0_in_b1_place = i << 8;
    unsigned short b1_in_b0_place = i >> 8;

    return b0_in_b1_place | b1_in_b0_place;
}

unsigned short swap_bytes_condensed(unsigned short i)
{
    return (i << 8) | (i >> 8);
}
