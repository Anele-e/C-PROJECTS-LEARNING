#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compareUserWithComp(char USER, char COMP)
{
    if ((USER == 's' && COMP == 'p') || (USER == 'p' && COMP == 'r') || (USER == 'r' && COMP == 's'))
    {
        return 0; // win
    }
    else if (USER == COMP)
    {
        return 2; // Draw
    }
    else
    {
        return 1; // loss
    }
}

int main()
{
    char USER;
    char COMP;
    int result;
    char playAgain;

    srand(time(0));

    do
    {
        do
        {
            printf("Welcome to Rock, Paper and Sciscors game\n");
            printf("Enter your choice r for Rock, s for Scissors and p for Paper\n");
            scanf(" %c", &USER);
        } while (USER != 'r' && USER != 'p' && USER != 's');

        int N = 3 * 500;
        int value = rand() % (N + 1);
        if (value < 500)
        {
            COMP = 'r';
        }
        else if (value > 2 * 500)
        {
            COMP = 'p';
        }
        else
        {
            COMP = 's';
        }

        printf("Player 2 hand: %c\n", COMP);

        result = compareUserWithComp(USER, COMP);

        if (result == 0)
        {
            printf("You are the winner!\n");
        }
        else if (result == 2)
        {
            printf("It's a Draw.\n");
        }
        else
        {
            printf("Player 2 wins and you lose.\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y');

    return 0;
}