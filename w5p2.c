/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Mehrnoosh Sarang
Student ID#: 1128498227
Email      : msarang@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void ) {
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
    const int JAN=1;
    const int DEC=12;
    int year, month, j;
    double morningRate,eveningRate,morning_TotalRating,evening_TotalRating;
    printf("General Well-being Log\n"
           "======================\n");
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year <MIN_YEAR || year >MAX_YEAR){
            printf("   ERROR: The year must be between %d and %d inclusive\n",MIN_YEAR,MAX_YEAR);
        }
        else if (month < JAN || month > DEC){
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    }while((year <MIN_YEAR  || year > MAX_YEAR) || (month < JAN || month > DEC));
    putchar('\n');
    printf("*** Log date set! ***\n\n");

    for ( j=1; j<= LOG_DAYS; j++) {
        switch (month) {
            case 1:
                printf("%d-JAN-0%d\n", year, j);
                break;
            case 2:
                printf("%d-FEB-0%d\n", year, j);
                break;
            case 3:
                printf("%d-MAR-0%d\n", year, j);
                break;
            case 4:
                printf("%d-APR-0%d\n", year, j);
                break;
            case 5:
                printf("%d-MAY-0%d\n", year, j);
                break;
            case 6:
                printf("%d-JUN-0%d\n", year, j);
                break;
            case 7:
                printf("%d-JULY-0%d\n", year, j);
                break;
            case 8:
                printf("%d-AUG-0%d\n", year, j);
                break;
            case 9:
                printf("%d-SEP-0%d\n", year, j);
                break;
            case 10:
                printf("%d-OCT-0%d\n", year, j);
                break;
            case 11:
                printf("%d-NOV-0%d\n", year, j);
                break;
            case 12:
                printf("%d-DEC-0%d\n", year, j);
                break;
        }
        do {
            printf("\n   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRate);
            if (morningRate < 0.0 || morningRate > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }else
                morning_TotalRating += morningRate;

        } while (morningRate < 0.0 || morningRate > 5.0);
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRate);
            if (eveningRate < 0.0 || eveningRate > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }else
                evening_TotalRating += eveningRate;

        } while (eveningRate < 0.0 || eveningRate > 5.0);

    }
    printf("\nSummary\n"
           "=======\n");
    printf("Morning total rating: %.3lf\n",morning_TotalRating);
    printf("Evening total rating: %.3lf\n",evening_TotalRating);
    printf("----------------------------\n"
           "Overall total rating: %.3lf\n\n",morning_TotalRating+evening_TotalRating);
    printf("Average morning rating: %.1lf\n",morning_TotalRating / LOG_DAYS);
    printf("Average evening rating: %.1lf\n",evening_TotalRating / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %.1lf\n\n",(evening_TotalRating / LOG_DAYS + morning_TotalRating / LOG_DAYS)/2);

    return 0;
}
