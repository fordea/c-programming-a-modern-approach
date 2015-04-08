#include <stdio.h>
#include <string.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);
char *byte_to_binary_str(int byte);
void print_int_bits(int value);

int main(void)
{
    int shift_amt = 4;
    unsigned int value = 0x12345678;

    printf("\nOriginal value\n");
    print_int_bits(value);
    printf("Hex\t%x\n\n", value);

    printf("\nRotated left by %d bit(s)\n", shift_amt);
    print_int_bits(rotate_left(value, shift_amt));
    printf("Hex\t%x\n\n", rotate_left(value, shift_amt));

    printf("\nRotated right by %d bit(s)\n", shift_amt);
    print_int_bits(rotate_right(value, shift_amt));
    printf("Hex\t%x\n\n", rotate_right(value, shift_amt));

    return 0;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return (i << n) | (i >> (sizeof(int) * 8) - n);
}

unsigned int rotate_right(unsigned int i, int n)
{
    return (i << (sizeof(int) * 8) - n) | (i >> n);
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

    printf("Binary\t");
    for (i = sizeof(int) - 1; i >= 0; i--) {
        printf("%s ", byte_to_binary_str(value >> (i * 8)));
    }
    printf("\n");
}
