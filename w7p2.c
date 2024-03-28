/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  :Mehrnoosh sarang
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
#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTIPLE 5

struct PlayerInfo {
    int lives;
    char symbol;
    int treasure_count;
    int history[MAXIMUM_PATH_LENGTH];
    int treasure_found;
    int position;
};

struct GameInfo {
    int max_moves;
    int path_length;
    int bombs_location[MAXIMUM_PATH_LENGTH];
    int treasure[MAXIMUM_PATH_LENGTH];
};

int main(void) {
    struct PlayerInfo player = {0};
    struct GameInfo game = {0};
//    int moves_remaining;
//    int lives_remaining;
    const char vacant = '-';
    const char bomb = '!';
    const char treasure = '$';
    const char both = '&';
    const char none_symbol = '.';

    char position_item[MAXIMUM_PATH_LENGTH] = {0};

    int valid, flag, i, j;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES) {
            printf("     Must be between %d and %d!\n", MINIMUM_LIVES, MAXIMUM_LIVES);
            valid = 0;
        }
    } while (valid == 0);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        valid = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MINIMUM_PATH_LENGTH,
               MAXIMUM_PATH_LENGTH);
        scanf("%d", &game.path_length);

        if ((game.path_length < MINIMUM_PATH_LENGTH || game.path_length > MAXIMUM_PATH_LENGTH) ||
            (game.path_length % MULTIPLE > 0)) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MINIMUM_PATH_LENGTH,
                   MAXIMUM_PATH_LENGTH);
            valid = 0;
        }
    } while (valid == 0);

    do {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_moves);

        if (game.max_moves<player.lives || game.max_moves>(int)(0.75 * game.path_length))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int) (0.75 * game.path_length));
            valid = 0;
        }
    } while (valid == 0);

    putchar('\n');
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

    for (i = 0; i < game.path_length; i += MULTIPLE) {
//        int j;
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++) {
            scanf("%d", &game.bombs_location[i + j]);
        }
    }


    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

    for (i = 0; i < game.path_length; i += MULTIPLE) {
//        int j;
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        for (j = 0; j < MULTIPLE; j++) {
            scanf("%d", &game.treasure[i + j]);
        }
    }

    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.path_length);

    printf("   Bombs      : ");
    for (i = 0; i < game.path_length; i++) {
        printf("%d", game.bombs_location[i]);
    }
    putchar('\n');


    printf("   Treasure   : ");
    for (i = 0; i < game.path_length; i++) {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n");


    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");


    printf("  ");
    for (i = 0; i < game.path_length; i++) {

        if (position_item[i] == both) {
            printf("%c", both);
        } else if (position_item[i] == treasure) {
            printf("%c", treasure);
        } else if (position_item[i] == none_symbol) {
            printf("%c", none_symbol);
        } else if (position_item[i] == bomb) {
            printf("%c", bomb);
        } else {
            printf("%c", vacant);
        }
    }
    putchar('\n');

    printf("  ");

    //ruler...

    for (i = 1, j = 1; i <= game.path_length; i++) {
        if (i % 10 == 0) {
            printf("%d", j);
            j++;
        } else {
            printf("|");
        }
    }

    putchar('\n');
    printf("  ");
    for (i = 1, j = 1; i <= game.path_length; i++) {
        if (i % 10 == 0) {
            printf("0");
            j = 1;
        } else {
            printf("%d", j);
            j++;
        }
    }


    putchar('\n');
    printf("+---------------------------------------------------+\n"
           "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
           "+---------------------------------------------------+\n",
           player.lives, player.treasure_found, game.max_moves);


    do {
        do {
            valid = 1;
            flag = 1;


            printf("Next Move [1-%d]: ", game.path_length);
            scanf("%d", &player.position);


            if (player.position <= 0 || player.position > game.path_length) {
                printf("  Out of Range!!!\n");
                flag = 0;
            }

        } while (!flag);


        // bomb and treasure...!!$$

        if (game.treasure[player.position - 1] == 1 &&
            game.bombs_location[player.position - 1] == 1) {
            putchar('\n');
            printf("===============> [&] !!! BOOOOOM !!! [&]\n"
                   "===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.history[player.position - 1] = 1;
            player.lives--;
            player.treasure_found++;
            game.max_moves--;
            position_item[player.position - 1] = both;
            valid = 0;
        } else if (game.treasure[player.position - 1] == 1 &&
                   game.bombs_location[player.position - 1] == 0) {
            putchar('\n');
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.history[player.position - 1] = 1;
            player.treasure_found++;
            game.max_moves--;
            position_item[player.position - 1] = treasure;
            valid = 0;
        }


            // nothing found....

        else if (game.treasure[player.position - 1] == 0 &&
                 game.bombs_location[player.position - 1] == 0 &&
                 player.history[player.position - 1] == 0) {
            putchar('\n');
            printf("===============> [.] ...Nothing found here... [.]\n");
            player.history[player.position - 1] = 1;
            game.max_moves--;
            position_item[player.position - 1] = none_symbol;
            valid = 0;
        }


            // bomb found ..!!

        else if (game.treasure[player.position - 1] == 0 &&
                 game.bombs_location[player.position - 1] == 1) {
            putchar('\n');
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.history[player.position - 1] = 1;
            player.lives--;
            game.max_moves--;
            position_item[player.position - 1] = bomb;
            valid = 0;
        } else {
            putchar('\n');
            printf("===============> Dope! You've been here before!\n");
            player.history[player.position - 1] = 0;
            valid = 0;
        }



        if (player.lives == 0) {
            printf("\nNo more LIVES remaining!\n");
            valid = 1;
        }


        else if (game.max_moves == 0) {
            printf("\nNo more MOVES remaining!\n");
            valid = 1;
        }



        putchar('\n');
        printf("  ");
        for (i = 1; i < (player.position + 1); i++) {
            if (i != player.position) {
                printf(" ");
            } else if (player.position == 0) {
                printf(" ");
            } else {
                printf("%c\n", player.symbol);
            }
        }



        printf("  ");
        for (i = 0; i < game.path_length; i++) {

            if (position_item[i] == both) {
                printf("%c", both);
            } else if (position_item[i] == treasure) {
                printf("%c", treasure);
            } else if (position_item[i] == none_symbol) {
                printf("%c", none_symbol);
            } else if (position_item[i] == bomb) {
                printf("%c", bomb);
            } else {
                printf("%c", vacant);
            }
        }


        putchar('\n');

        printf("  ");


        // ruler logic...


        for (i = 1, j = 1; i <= game.path_length; i++) {
            if (i % 10 == 0) {
                printf("%d", j);
                j++;
            } else {
                printf("|");
            }
        }

        putchar('\n');
        printf("  ");
        for (i = 1, j = 1; i <= game.path_length; i++) {
            if (i % 10 == 0) {
                printf("0");
                j = 1;
            } else {
                printf("%d", j);
                j++;
            }
        }

        putchar('\n');
        printf("+---------------------------------------------------+\n"
               "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
               "+---------------------------------------------------+\n",
               player.lives, player.treasure_found, game.max_moves);


    } while (!valid);


    for (i = 0; i < game.path_length; i++) {
        player.history[i] = 0;
    }

    // END

    putchar('\n');
    printf("##################\n"
           "#   Game over!   #\n"
           "##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;

}
