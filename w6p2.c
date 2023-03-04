
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MINIMUM_ITEM 1
#define MAXIMUM_ITEM 10
int main(void)
{
    const double minimumIncome = 500.00, maximumIncome = 400000.00,minimumCost = 100.00;
    const char affirmative = 'y', negative = 'n';
    const int mustHave = 1,important = 2;
    const int want = 3;
    const int allItems = 1;
    const int byPriority = 2;
    const int quit = 0;
    int selection;
    int priorityChoice;
    int year = 0;
    double netIncome = 0;
    double overallCost = 0;
    double totalPriority = 0;
    int wishList;
    int i;
    int valid = 1;
    int priority[MAXIMUM_ITEM] = { 0 };
    double itemCost[MAXIMUM_ITEM] = { 0.00f };
    char financeOption[MAXIMUM_ITEM] = { 0 };


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        valid = 1;
        putchar('\n');
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);


        if (netIncome < minimumIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", minimumIncome);
            valid = 0;
        }
        if (netIncome > maximumIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", maximumIncome);
            valid = 0;
        }
    } while (valid == 0);

    do
    {
        valid = 1;
        putchar('\n');
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wishList);

        if (wishList < 1 || wishList > 10)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", MINIMUM_ITEM, MAXIMUM_ITEM);
            valid = 0;
        }
    } while (valid == 0);
    putchar('\n');

    for (i = 0; i < wishList; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do
        {

            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);

            if (itemCost[i] < minimumCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minimumCost);
                valid = 0;
            }
        } while (valid == 0);

        do
        {
            valid = 1;
            printf("   How important is it to you? [%d=must have, %d=important, %d=want]: ", mustHave, important, want);
            scanf("%d", &priority[i]);
            totalPriority += itemCost[i];

            if (priority[i] != mustHave && priority[i] != important && priority[i] != want)
            {
                printf("      ERROR: Value must be between %d and %d\n", mustHave, want);
                valid = 0;
            }
        } while (valid == 0);

        do
        {
            valid = 1;
            printf("   Does this item have financing options? [%c/%c]: ", affirmative, negative);
            scanf(" %c", &financeOption[i]);

            if (financeOption[i] != affirmative && financeOption[i] != negative)
            {
                printf("      ERROR: Must be a lowercase '%c' or '%c'\n", affirmative, negative);
                valid = 0;
            }
        } while (valid == 0);
        overallCost += itemCost[i];
        putchar('\n');
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < wishList; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], itemCost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", overallCost);

    do
    {
        valid = 1;
        printf("How do you want to forecast your wish list?\n");
        printf(" %d. All items (no filter)\n", allItems);
        printf(" %d. By priority\n", byPriority);
        printf(" %d. Quit/Exit\n", quit);
        printf("Selection: ");
        scanf("%d", &selection);
        if (selection == quit)
        {
            valid = 1;
        }
        else if (selection < allItems || selection > byPriority)
        {
            printf("\nERROR: Invalid menu selection.\n\n");
            valid = 0;
        }
        else if (selection == allItems)
        {
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", overallCost);
            year = ((overallCost + (netIncome - 1)) / netIncome);


            printf("Forecast: %d years, %d months\n", (int)year / 12, (int)year % 12);
            valid = 0;

            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");

        }
        else if (selection == byPriority)
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityChoice);
            printf("\n");

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityChoice);
            totalPriority = 0;
            for (i = 0; i < wishList; i++)
            {

                if (priority[i] == priorityChoice) 
                {
                    totalPriority += itemCost[i];
                }
                
            }

            year = ((totalPriority + (netIncome - 1)) / netIncome);

            printf("Amount:   $%.2lf\n", totalPriority);
            printf("Forecast: %d years, %d months\n", (int)year / 12, (int)year % 12);
            totalPriority = 0;

            valid = 0;
            for (i = 0; i < wishList; i++)
            {
                if (financeOption[i] == 'y' && priority[i] == priorityChoice) {
                    valid += 1;
                }
            }
            if (valid != 0)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            printf("\n");
            

            valid = 0;
        }
    } while (valid == 0);

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}