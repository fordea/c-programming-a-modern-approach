#include <stdio.h>
#include <string.h>

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))
#define GET_RED(color) ((color) & 0xff)
#define GET_GREEN(color) ((color) >> 8 & 0xff)
#define GET_BLUE(color) ((color) >> 16 & 0xff)

char *byte_to_binary(int n)
{
    static char bits[9];
    bits[0] = '\0';

    int i;
    for (i = 0x80; i > 0; i >>= 1)
    {
        strcat(bits, ((n & i) == i) ? "1" : "0");
    }

    return bits;
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
        printf("Byte %d: %s\n", i, byte_to_binary(colors >> (i * 8)));
    }

    printf("\nRed (Byte 0)\n");
    printf("Binary: %s\tDecimal: %ld\n", byte_to_binary(colors), GET_RED(colors));

    printf("Green (Byte 1)\n");
    printf("Binary: %s\tDecimal: %ld\n", byte_to_binary(colors >> 8), GET_GREEN(colors));

    printf("Blue (Byte 2)\n");
    printf("Binary: %s\tDecimal: %ld\n\n", byte_to_binary(colors >> 16), GET_BLUE(colors));
}
