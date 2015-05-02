/*********************************************************
* From C PROGRAMMING: A MODERN APPROACH, Second Edition *
* By K. N. King                                         *
* Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
* All rights reserved.                                  *
* This program may be freely distributed for class use, *
* provided that this copyright notice is retained.      *
*********************************************************/

/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *fpin;
    FILE *fpout;

    if (argc != 3) {
        printf("Usage: programname inputfile outputfile.\n");
        exit(EXIT_FAILURE);
    }

    if ((fpin = fopen(argv[1], "rb")) == NULL) {
        printf("Error, cannot open input file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fpout = fopen(argv[2], "wb")) == NULL) {
        printf("Error, cannot create output file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }


    int orig_char, new_char;

    while ((orig_char = getc(fpin)) != EOF) {
        new_char = orig_char ^ KEY;
        putc(new_char, fpout);
    }

    fclose(fpin);
    fclose(fpout);
    return 0;
}
