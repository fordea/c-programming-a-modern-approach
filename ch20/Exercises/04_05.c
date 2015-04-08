#include <stdio.h>
#include <string.h>

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))
#define GET_RED(color) ((color) & 0xff)
#define GET_GREEN(color) ((color) >> 8 & 0xff)
#define GET_BLUE(color) ((color) >> 16 & 0xff)

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

int main(void)
{
    int red = 25;
    int green = 195;
    int blue = 98;

    long colors = MK_COLOR(red, green, blue);
    int i;

    printf("All bytes in colors\n");
    for (i = 0; i < sizeof(long); i++) {
        printf("Byte %d: %s\n", i, byte_to_binary_str(colors >> (i * 8)));
    }

    printf("\nRed (Byte 0)\n");
    printf("Binary: %s\tDecimal: %ld\n", byte_to_binary_str(colors), GET_RED(colors));

    printf("Green (Byte 1)\n");
    printf("Binary: %s\tDecimal: %ld\n", byte_to_binary_str(colors >> 8), GET_GREEN(colors));

    printf("Blue (Byte 2)\n");
    printf("Binary: %s\tDecimal: %ld\n\n", byte_to_binary_str(colors >> 16), GET_BLUE(colors));
}
