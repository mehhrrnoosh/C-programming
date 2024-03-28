/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msarang@myseneca.ca
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define MIN_LIVES_NUMBER 1
#define MAX_LIVES_NUMBER 10

#define MULTIPLE 5

#define  MINIMUM_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

struct PlayerInfo
{
    int lives_number;
    char symbol;
    int count;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int moves_number;
    int path_lenght;
    int bombs_location[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

int main()
{
    struct PlayerInfo player;
    struct GameInfo game;
    int valid = 0, i, k, j;

    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do
    {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.lives_number);

        if (player.lives_number < MIN_LIVES_NUMBER || player.lives_number > MAX_LIVES_NUMBER)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES_NUMBER, MAX_LIVES_NUMBER);
            valid = 0;
        }
    } while (!valid);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n"
           "------------------\n");
    do
    {
        valid = 1;
        printf("Set the path length (a multiple of 5 between %d-%d): ", MINIMUM_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.path_lenght);

        if ((game.path_lenght < MINIMUM_PATH_LENGTH || game.path_lenght > MAX_PATH_LENGTH) || (game.path_lenght % MULTIPLE != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MINIMUM_PATH_LENGTH, MAX_PATH_LENGTH);
            valid = 0;
        }
    } while (!valid);

    do
    {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves_number);

        if (game.moves_number < player.lives_number || game.moves_number >(int) (0.75 * game.path_lenght))

        {
            printf("    Value must be between %d and %d\n", player.lives_number, (int)(0.75 * game.path_lenght));
            valid = 0;
        }

    } while (!valid);
    putchar('\n');


    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n", MULTIPLE);
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_lenght);


    for (i = 0; i < game.path_lenght; i += MULTIPLE)
    {
//        int j;
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++)
        {
            scanf("%d", &game.bombs_location[i + j]);
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n"
           "------------------\n");

    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n", MULTIPLE);


    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_lenght);

    for (i = 0; i < game.path_lenght; i += MULTIPLE)
    {
//        int j;
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++)
        {
            scanf("%d", &game.treasure[i + j]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives_number);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    putchar('\n');

    printf("Game:\n");
    printf("   Path Length: %d\n", game.path_lenght);


    printf("   Bombs      : ");
    for (j = 0; j < game.path_lenght; j++)
    {
        printf("%d", game.bombs_location[j]);
    }
    putchar('\n');


    printf("   Treasure   : ");
    for (k = 0; k < game.path_lenght; k++)
    {
        printf("%d", game.treasure[k]);
    }
    printf("\n\n");
    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");
    return 0;
}
