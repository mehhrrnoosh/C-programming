/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define  MIN_YEAR 2012
#define  MAX_YEAR 2022
#define  LOG_DAYS 3
int main(void)
{

    int year, month,flag,i;
    const int JAN =1, DEC=12;
    double morningRate, eveningRate, morningTotalRate,eveningTotalrate;

    printf("General Well-being Log\n");
    printf("======================\n");
    do {

        flag=1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %4d and %4d inclusive\n", MIN_YEAR, MAX_YEAR);
            flag=0;
        }
        if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            flag=0;
        }
    }while (!flag);

    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");

    for ( i=1; i<= LOG_DAYS; i++) {
        switch (month) {
            case 1:
                printf("%d-JAN-0%d\n", year, 1);
                break;

            case 2:
                printf("%d-FEB-0%d\n", year, i);
                break;

            case 3:
                printf("%d-MAR-0%d\n", year, i);
                break;
            case 4:
                printf("%d-APR-0%d\n", year, i);
                break;
            case 5:
                printf("%d-MAY-0%d\n", year, i);
                break;
            case 6:
                printf("%d-JUN-0%d\n", year, i);
                break;
            case 7:
                printf("%d-JULY-0%d\n", year, i);
                break;
            case 8:
                printf("%d-AUG-0%d\n", year, i);
                break;
            case 9:
                printf("%d-SEP-0%d\n", year, i);
                break;
            case 10:
                printf("%d-OCT-0%d\n", year, i);
                break;
            case 11:
                printf("%d-NOV-0%d\n", year, i);
                break;
            case 12:
                printf("%d-DEC-0%d\n", year, i);
                break;
        }

        do {
            flag = 1;
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRate);

            if (morningRate < 0.0 || morningRate > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                flag = 0;

            } else {
                morningTotalRate += morningRate;
            }
        } while (!flag);

        do {
            flag = 1;
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRate);

            if (eveningRate < 0.0 || eveningRate > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                flag = 0;
            } else {
                eveningTotalrate += eveningRate;
            }
        } while (!flag);
        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n",morningTotalRate);
    printf("Evening total rating:  %.3lf\n",eveningTotalrate);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningTotalRate + eveningTotalrate);
    printf("Average morning rating:  %.1lf\n",morningTotalRate / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n",eveningTotalrate / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n\n",(eveningTotalrate / LOG_DAYS + morningTotalRate / LOG_DAYS)/2);





    return 0;
}
