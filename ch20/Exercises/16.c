#include <stdio.h>
#include <math.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD; /* int is 32 bit on my machine */

/* Any struct members prefixed by d_ are dummy registers
 * to accomodate the high order half of the 32 bit registers */
union {
    struct { /* 32 bit registers */
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct { /* 16 bit registers */
        WORD d_ax, ax;
        WORD d_bx, bx;
        WORD d_cx, cx;
        WORD d_dx, dx;
    } word;
    struct { /*  8 bit registers */
        BYTE d_al, d_ah, al, ah;
        BYTE d_bl, d_bh, bl, bh;
        BYTE d_cl, d_ch, cl, ch;
        BYTE d_dl, d_dh, dl, dh;
    } byte;
} regs;

int main(void)
{
    regs.dword.eax = 0x12345678;
    printf("AX: %x\n", regs.word.ax);
    printf("DAX: %x\n", regs.word.d_ax);
    printf("EAX: %x\n", regs.dword.eax);

    regs.word.ax = 0;
    printf("AX: %x\n", regs.word.ax);
    printf("DAX: %x\n", regs.word.d_ax);
    printf("EAX: %x\n", regs.dword.eax);
}
