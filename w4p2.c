

/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  :Mehrnoosh Sarang
Student ID#:128498227
Email      :msarang@myseneca.ca
Section    :ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int applesNo, orangesNo, pearsNo, tomatoesNo, cabbagesNo;
    int shoppingCheck;
    int pickApple, pickOrange, pickPear, pickTomatoes, pickCabbages;
do{

    printf("Grocery Shopping\n");
    printf("================\n");
    do {
        printf("How many APPLES do you need? : ");
        scanf("%d", &applesNo);
        if (applesNo < 0) {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (applesNo < 0);
    putchar('\n');

    do {
        printf("How many ORANGES do you need? : ");
        scanf("%d", &orangesNo);
        if (orangesNo < 0) {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (orangesNo < 0);
    putchar('\n');
    do {
        printf("How many PEARS do you need? : ");
        scanf("%d", &pearsNo);
        if (pearsNo < 0) {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (pearsNo < 0);
    putchar('\n');
    do {
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoesNo);
        if (tomatoesNo < 0) {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (tomatoesNo < 0);
    putchar('\n');
    do {
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbagesNo);
        if (cabbagesNo < 0) {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (cabbagesNo < 0);
    putchar('\n');
    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    if (applesNo > 0) {
        do {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pickApple);
            if (pickApple <= 0) {
                printf("ERROR: You must pick at least 1!");
                putchar('\n');
            } else if (pickApple > applesNo) {
                printf("You picked too many... only %d more APPLE(S) are needed.", applesNo);
                putchar('\n');
            } else if (pickApple <= applesNo) {
                applesNo = applesNo - pickApple;
                if (applesNo > 0) {
                    printf("Looks like we still need some APPLES...");
                    putchar('\n');
                }
            }
        } while (applesNo);
        printf("Great, that's the apples done!\n\n");
    }
        if (orangesNo > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickOrange);
                if (pickOrange <= 0) {
                    printf("ERROR: You must pick at least 1!");
                    putchar('\n');
                } else if (pickOrange > orangesNo) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.", orangesNo);
                    putchar('\n');
                } else if (pickOrange <= orangesNo) {
                    orangesNo = orangesNo- pickOrange;
                    if (orangesNo > 0) {
                        printf("Looks like we still need some ORANGES...");
                        putchar('\n');
                    }
                }
            } while (orangesNo);
            printf("Great, that's the oranges done!\n\n");
    }
    if (pearsNo > 0) {
        do {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pickPear);
            if (pickPear <= 0) {
                printf("ERROR: You must pick at least 1!");
                putchar('\n');
            } else if (pickPear > pearsNo) {
                printf("You picked too many... only %d more PEAR(S) are needed.", pearsNo);
                putchar('\n');
            } else if (pickPear <= pearsNo) {
                pearsNo = pearsNo- pickPear;
                if (pearsNo > 0) {
                    printf("Looks like we still need some PEARS...");
                    putchar('\n');
                }
            }
        } while (pearsNo);
        printf("Great, that's the pears done!\n\n");
    }
    if (tomatoesNo > 0) {
        do {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pickTomatoes);
            if (pickTomatoes <= 0) {
                printf("ERROR: You must pick at least 1!");
                putchar('\n');
            } else if (pickTomatoes > tomatoesNo) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.", tomatoesNo);
                putchar('\n');
            } else if (pickTomatoes <= tomatoesNo) {
                tomatoesNo = tomatoesNo- pickTomatoes;
                if (tomatoesNo > 0) {
                    printf("Looks like we still need some TOMATOES...");
                    putchar('\n');
                }
            }
        } while (tomatoesNo);
        printf("Great, that's the tomatoes done!\n\n");
    }

    if (cabbagesNo > 0) {
        do {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pickCabbages);
            if (pickCabbages <= 0) {
                printf("ERROR: You must pick at least 1!");
                putchar('\n');
            } else if (pickCabbages > cabbagesNo) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.", cabbagesNo);
                putchar('\n');
            } else if (pickCabbages <= cabbagesNo) {
                cabbagesNo = cabbagesNo - pickCabbages;
                if (cabbagesNo > 0) {
                    printf("Looks like we still need some CABBAGES...");
                    putchar('\n');
                }
            }
        } while (cabbagesNo);
        printf("Great, that's the cabbages done!\n\n");
    }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shoppingCheck);
        putchar('\n');

    }while (shoppingCheck!=0);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}

