#include <stdio.h>
#include <stdint.h>

int main(void)
{
    typedef int8_t Int8;
    typedef int16_t Int16;
    typedef int32_t Int32;

    printf("Size of int8: %zu byte (%zu bits).\n", sizeof(Int8), sizeof(Int8) * 8);
    printf("Size of int16: %zu bytes (%zu bits).\n", sizeof(Int16), sizeof(Int16) * 8);
    printf("Size of int32: %zu bytes (%zu bits).\n", sizeof(Int32), sizeof(Int32) * 8);

    return 0;
}
