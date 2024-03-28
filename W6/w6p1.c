/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msarang@myseneca.ca
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_ITEMS 1
#define MAX_ITEMS 10

int main(void)
{

    double monthlyNetIncome,cost [MAX_ITEMS],totalCost=0;
    const double minIncome = 500, maxIncome= 400000, minimumCost = 100.00;
    int flag,i,wishListNumber,priority [MIN_ITEMS];
    char financeOption [ MAX_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        flag = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf",&monthlyNetIncome);
        if ( monthlyNetIncome < minIncome )
        {
            printf( "ERROR: You must have a consistent monthly income of at least $%.2lf\n",minIncome);
            flag = 0;
        }
        if ( monthlyNetIncome >= maxIncome )
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n",maxIncome);
            flag=0;

        }
        putchar('\n');
    } while (!flag );

    do
    {
        flag =1 ;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d",&wishListNumber);

        if ( wishListNumber <MIN_ITEMS || wishListNumber > MAX_ITEMS )
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            flag =0;
        }
        putchar('\n');
    } while ( ! flag );

    for (i=0; i < wishListNumber; i++) {
        printf("Item-%d Details:\n", i + 1);

        do {
            flag = 1;
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < minimumCost) {
                printf("      ERROR: Cost must be at least $%.2lf\n", minimumCost);
                flag = 0;
            }

        } while (!flag);
        do {
            flag = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
                flag = 0;
            }
        } while (!flag);
        do {
            flag = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i]);
            if (!(financeOption[i] == 'n' || financeOption[i] == 'y')) {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                flag = 0;
            }
        } while (!flag);
        printf("\n");
    }
        printf("Item Priority Financed        Cost\n"
               "---- -------- -------- -----------\n");
        for ( i =0; i <wishListNumber; i++ )
        {
            printf("%3d  %5d    %5c    %11.2lf\n",i+1,priority [i],financeOption[i],cost[i] );
            totalCost+=cost[i];
        }
        printf("---- -------- -------- -----------\n");
        printf("                      $%11.2lf\n\n",totalCost);
        printf("Best of luck in all your future endeavours!\n");

    return 0;
}
