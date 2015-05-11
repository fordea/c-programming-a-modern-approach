#include <stdio.h>
#include <stdlib.h>

void windows_to_unix_file(char *infilename, char *outfilename);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: programname inputfile outputfile.\n");
        exit(EXIT_FAILURE);
    }
    windows_to_unix_file(argv[1], argv[2]);
    return 0;
}

void windows_to_unix_file(char *infilename, char *outfilename)
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
        if (ch == '\x0d') {
            fputc('\x0a', fpout);
        } else if (ch != '\x0a') {
            fputc(ch, fpout);
        }
    }
    fclose(fpin);
    fclose(fpout);
}
