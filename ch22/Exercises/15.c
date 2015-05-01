#include <stdio.h>

#define RECORD_BYTES 64L

int main(void)
{
    FILE *fp;
    long int n = 30;

    /* Part (a) Move to beginning of Record n */
    fseek(fp, n * RECORD_BYTES, SEEK_SET);

    /* Part (b) Move to beginning of last Record */
    fseek(fp, -RECORD_BYTES, SEEK_END);

    /* Part (c) Move to beginning of next record */
    fseek(fp, RECORD_BYTES, SEEK_CUR);

    /* Part (d) Move to beginning of Record that's two Records back */
    fseek(fp, 2 * (-RECORD_BYTES), SEEK_CUR);

    fclose(fp);
    return 0;
}
