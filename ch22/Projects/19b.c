#include <stdio.h>
#include <stdlib.h>

void unix_to_windows_file(char *infilename, char *outfilename);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: programname inputfile outputfile.\n");
        exit(EXIT_FAILURE);
    }
    unix_to_windows_file(argv[1], argv[2]);
    return 0;
}

void unix_to_windows_file(char *infilename, char *outfilename)
{
    FILE *fpin, *fpout;
    int ch;
    if ((fpin = fopen(infilename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open input file %s.\n", infilename);
        exit(EXIT_FAILURE);
    }
    if ((fpout = fopen(outfilename, "wb")) == NULL) {
        fprintf(stderr, "Cannot open output file %s.\n", outfilename);
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fpin)) != EOF) {
        if (ch == '\x0a') {
            fputc('\x0d', fpout);
            fputc(ch, fpout);
        } else {
            fputc(ch, fpout);
        }
    }
    fclose(fpin);
    fclose(fpout);
}
