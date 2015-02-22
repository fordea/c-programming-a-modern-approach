#include <stdio.h>

int main(void)
{
    int arr[5][5] = {0}, row, col, score; 
    int high_score = 0, low_score = 0;
    float avg_score = 0.0f;

    /* Populate 5 x 5 array */
    for (row = 0; row < 5; row++) {
        printf("Enter 5 Quiz scores for Student %d :", row + 1);
        scanf("%d %d %d %d %d", &arr[row][0], &arr[row][1], 
                &arr[row][2], &arr[row][3], &arr[row][4]);
    }

    /* Calculate student scores*/
    printf("\n*Total scores*\n");
    for (row = 0; row < 5; row++) {
        score = 0;
        printf("Student %d: ", row + 1);
        for (col = 0; col < 5; col++) {
            score += arr[row][col];
        }
        printf("%d\n", score);
    }

    /* Calculate quiz stats */
    for (col = 0; col < 5; col++) {
        avg_score = 0.0f;
        high_score = 0;
        low_score = arr[col][0];

        printf("\n*Stats for Quiz %d*\n", col + 1);
        for(row = 0; row < 5; row++) {
            avg_score += arr[row][col];
            high_score = arr[row][col] > high_score ? arr[row][col] : high_score;
            low_score = arr[row][col] < low_score ? arr[row][col] : low_score;
        }
        printf("Average score: %2.1f\n", avg_score / 5);
        printf("Highest score: %2d\n", high_score);
        printf("Lowest score:  %2d\n", low_score);
    }

    return 0;
}

    
    
