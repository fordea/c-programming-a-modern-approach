#include <stdio.h>
#include <math.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD; /* int is 32 bit on my machine */

/* Split the word registers in two to simulate dummy registers
 * to accomodate the high order half of the 32 bit registers.
 * struct assumes little-endian byte storage */
union {
    struct { /* 32 bit registers */
        DWORD eax;
        DWORD ebx;
        DWORD ecx;
        DWORD edx;
    } dword;
    struct { /* 16 bit registers */
        WORD axl, axh;
        WORD bxl, bxh;
        WORD cxl, cxh;
        WORD dxl, dxh;
    } word;
    struct { /*  8 bit registers */
        BYTE axll, axlh, axhl, axhh;
        BYTE bxll, bxlh, bxhl, bxhh;
        BYTE cxll, cxlh, cxhl, cxhh;
        BYTE dxll, dxlh, dxhl, dxhh;
    } byte;
} regs;

int main(void)
{
    regs.dword.eax = 0x12345678;
    printf("AX (low): %x\n", regs.word.axl);
    printf("AX (high): %x\n", regs.word.axh);
    printf("EAX: %x\n", regs.dword.eax);

    regs.word.axl = 0;
    printf("AX (low): %x\n", regs.word.axl);
    printf("AX (high): %x\n", regs.word.axh);
    printf("EAX: %x\n", regs.dword.eax);

    printf("AXL (low): %x\n", regs.byte.axll);
    printf("AXL (high): %x\n", regs.byte.axlh);
    printf("AXH (low): %x\n", regs.byte.axhl);
    printf("AXH (high): %x\n", regs.byte.axhh);

}
