#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0, losses = 0;
    char ch;
    srand((unsigned) time(NULL));
    
    do {
        printf("\n");
        if (play_game()) {
            wins++;
            printf("You win!\n");
        } else {
            losses++;
            printf("You lose!\n");
        }

        printf("\nPlay again? (y/n) ");
        scanf(" %c", &ch); 
    } while (toupper(ch) == 'Y');

    printf("\nWins: %d\tLosses: %d", wins, losses);

    return 0;
}

int roll_dice(void)
{
    int roll1, roll2;

    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;

    return roll1 + roll2;
}

bool play_game(void)
{
    int rolls = roll_dice();
    int point = rolls;
    printf("You rolled: %d\n", rolls);

    if (rolls == 7 || rolls == 11)
        return true;
    else if (rolls <= 3 || rolls == 12)
        return false;
    else
        printf("Your point is: %d\n", rolls);

    while (true) {
        rolls = roll_dice();
        printf("You rolled: %d\n", rolls);

        if (rolls == point)
            return true;
        else if (rolls == 7)
            return false;
    }
}
