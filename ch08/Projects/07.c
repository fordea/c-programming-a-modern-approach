#include <stdio.h>

int main(void)
{
    int arr[5][5] = {0}, row, col, total;

    /* Populate 5 x 5 array */
    for (row = 0; row < 5; row++) {
        printf("Enter row %d :", row + 1);
        scanf("%d %d %d %d %d", &arr[row][0], &arr[row][1], 
                &arr[row][2], &arr[row][3], &arr[row][4]);
    }

    /* Calculate row totals */
    printf("Row totals: ");
    for (row = 0; row < 5; row++) {
        total = 0;
        for (col = 0; col < 5; col++) {
            total += arr[row][col];
        }
        printf("%d ", total);
    }

    /* Calculate column totals */
    printf("\nColumn totals: ");
    for (col = 0; col < 5; col++) {
        total = 0;
        for(row = 0; row < 5; row++) {
            total += arr[row][col];
        }
        printf("%d ", total);
    }

    return 0;
}

    
    
