/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Mehrnoosh sarang
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

int main(void)
{
    //variable declreation
    int apples, oranges, pears,tomatoes,cabbage;
    int flag, checkShopping;
    int applePicked,pearsPicked,tomatoPicked,orangePicked,cabbagePicked;
do {
    printf("Grocery Shopping\n");
    printf("================\n");


    do {
        flag = 0;
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        if (apples < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            flag = 1;
        }
    } while (flag != 0);
    printf("\n");
//
    do {
        flag = 0;
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        if (oranges < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            flag = 1;
        }
    } while (flag != 0);
    printf("\n");

    do {
        flag = 0;
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        if (pears < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            flag = 1;
        }
    } while (flag != 0);
    printf("\n");

    do {
        flag = 0;
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        if (tomatoes < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            flag = 1;
        }
    } while (flag != 0);
    printf("\n");

    do {
        flag = 0;
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbage);
        if (cabbage < 0) {
            printf("ERROR: Value must be 0 or more.\n");
            flag = 1;
        }
    } while (flag != 0);
    printf("\n--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    //Apple
    if (apples > 0) {
        do {

            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &applePicked);
            if (applePicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");

            } else if (applePicked > apples) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            } else if (applePicked <= apples) {
                apples = apples - applePicked;
                if (apples > 0) {
                    printf("Looks like we still need some APPLES...");
                    putchar('\n');
                }
            }
        } while (apples);
        printf("Great, that's the apples done!\n");
        printf("\n");
    }

    //Orange//
    if (oranges > 0) {
        do {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangePicked);
            if (orangePicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (orangePicked > oranges) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);

            } else if (orangePicked <= oranges) {
                oranges = oranges - orangePicked;
                if (oranges > 0) {
                    printf("Looks like we still need some ORANGES...");
                    putchar('\n');
                }
            }
        } while (oranges);
        printf("Great, that's the oranges done!\n");
        printf("\n");
    }

    //pears
    if (pears > 0) {
        do {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsPicked);
            if (pearsPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (pearsPicked > pears) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            } else if (pearsPicked <= pears) {
                pears = pears - pearsPicked;
                if (pears > 0) {
                    printf("Looks like we still need some PEARS...");

                    putchar('\n');
                }
            }
        }while (pears);
        printf("Great, that's the pears done!\n");
        printf("\n");
    }
    //tomato
    if (tomatoes > 0) {
        do {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoPicked);
            if (tomatoPicked <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (tomatoPicked > tomatoes) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            } else if (tomatoPicked <= tomatoes) {
                tomatoes = tomatoes - tomatoPicked;
                if (tomatoes > 0) {
                    printf("Looks like we still need some TOMATOES...");
                    putchar('\n');
                }
            }
        } while (tomatoes);
        printf("Great, that's the tomatoes done!\n");
        printf("\n");
    }
        //cabbage
        if (cabbage > 0) {
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &cabbagePicked);
                if (cabbagePicked <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                } else if (cabbagePicked > cabbage) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbage);
                } else if (cabbagePicked <= cabbage) {
                    cabbage = cabbage - cabbagePicked;
                    if (cabbage > 0) {
                        printf("Looks like we still need some CABBAGES...");
                        putchar('\n');
                    }
                }
            } while (cabbage);
            printf("Great, that's the cabbages done!\n");
            printf("\n");
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &checkShopping);
        printf("\n");
    } while ( checkShopping !=0 );
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}
