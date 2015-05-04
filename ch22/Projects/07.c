#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char BYTE;

void compress_file(char *filename);
void uncompress_file(char *filename);
bool is_compressed_file(char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: programname inputfile.\n");
        exit(EXIT_FAILURE);
    }

    if (is_compressed_file(argv[1])) {
        uncompress_file(argv[1]);
    }
    else {
        compress_file(argv[1]);
    }
}

bool is_compressed_file(char *filename) {
    char compression_ext[] = ".rle";
    char *p = filename;
    while (*p++);
    while (p >= filename && *p != '.') {
        p--;
    }
    return strcmp(p, compression_ext) == 0;
}

void compress_file(char *filename) {

    FILE *fpin;
    FILE *fpout;

    if ((fpin = fopen(filename, "rb")) == NULL) {
        printf("Error, cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char *outfilename = malloc(strlen(filename) + 5);
    strcpy(outfilename, filename);
    strcat(outfilename, ".rle");

    if ((fpout = fopen(outfilename, "wb")) == NULL) {
        printf("Error, cannot create file %s.\n", outfilename);
        exit(EXIT_FAILURE);
    }
    free(outfilename);

    BYTE origbyte;
    BYTE cmpbyte;
    int pos;
    BYTE sequence; //Allows sequences upto 255
    while (fread(&origbyte, sizeof(BYTE), 1, fpin) > 0) {
        sequence = 1;
        pos = ftell(fpin);
        while (fread(&cmpbyte, sizeof(BYTE), 1, fpin) > 0
                && cmpbyte == origbyte) {
            ++sequence;
        }
        fwrite(&sequence, sizeof(BYTE), 1, fpout);
        fwrite(&origbyte, sizeof(BYTE), 1, fpout);
        fseek(fpin, pos + (sequence - 1), SEEK_SET);
    }
    fclose(fpin);
    fclose(fpout);
}

void uncompress_file(char *filename)
{
    FILE *fpin;
    FILE *fpout;

    if ((fpin = fopen(filename, "rb")) == NULL) {
        printf("Error, cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char *outfilename = malloc(strlen(filename) - 3);
    strncpy(outfilename, filename, strlen(filename) - 4);

    if ((fpout = fopen(outfilename, "wb")) == NULL) {
        printf("Error, cannot create file %s.\n", outfilename);
        exit(EXIT_FAILURE);
    }
    free(outfilename);

    BYTE b;
    BYTE repetitions;
    int i = 0;
    while (fread(&b, sizeof(BYTE), 1, fpin) > 0) {
        if (i % 2 == 0) {
            repetitions = b;
        }
        else {
            for (int j = 0; j < repetitions; ++j) {
                fwrite(&b, sizeof(BYTE), 1, fpout);
            }
        }
        ++i;
    }
    fclose(fpin);
    fclose(fpout);
}
