#include <stdio.h>
#include <string.h>

#define INT_BITS (sizeof(int) * 8 - 1)

unsigned int reverse_bits(unsigned int n);
unsigned int reverse_bits_v2(unsigned int n);
char *byte_to_binary_str(int byte);
void print_int_bits(int value);

int main(void)
{
    /* unsigned int n = 0xff00ff00; */
    unsigned int n = 0xfabfe74d;
    printf("Original: ");
    print_int_bits(n);
    /* n = reverse_bits(n); */
    n = reverse_bits_v2(n);
    printf("Reversed: ");
    print_int_bits(n);
}

/* Reverse bits by copying to a new int in O(number of bits) */
unsigned int reverse_bits(unsigned int n)
{
    int i, m = 0;
    for (i = INT_BITS; i >= 0; i--) {
        if (n & (1 << i))
            m |= (1 << ((INT_BITS) - i));
    }
    return m;
}

/* Reverse bits in place in O(number of bits / 2)
 * Comapres bits 0..15 to bits 31..16 */
unsigned int reverse_bits_v2(unsigned int n)
{
    int i;
    for (i = 0; i <= INT_BITS / 2; i++) {
        /* Ignore if both bits to be swapped  match */
        if (((n >> INT_BITS - i) & 1) != ((n >> i) & 1)) {
            n ^= (1 << INT_BITS - i) | (1 << i);
        }
    }
    return n;
}

char *byte_to_binary_str(int byte)
{
    static char bit_string[9];
    bit_string[0] = '\0';

    int mask;
    for (mask = 0x80; mask > 0; mask >>= 1) {
        /* Check if the mask bit is set */
        strcat(bit_string, byte & mask ? "1" : "0");
    }

    return bit_string;
}

void print_int_bits(int value)
{
    static int i;

    for (i = sizeof(int) - 1; i >= 0; i--) {
        printf("%s ", byte_to_binary_str(value >> (i * 8)));
    }
    printf("\n");
}
