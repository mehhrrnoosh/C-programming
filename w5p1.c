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
int main(void)
{

    int year, month,flag;
    const int JAN =1, DEC=12;

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
    switch (month)
    {
        case 1:
            printf("Log starting date: %4d-JAN-01\n",year);
            break;

        case 2:
            printf("Log starting date: %4d-FEB-01\n",year);
            break;

        case 3:
            printf("Log starting date: %4d-MAR-01\n",year);
            break;
        case 4:
            printf("Log starting date: %4d-APR-01\n",year);
            break;
        case 5:
            printf("Log starting date: %4d-MAY-01\n",year);
            break;
        case 6:
            printf("Log starting date: %4d-JUNE-01\n",year);
            break;
        case 7:
            printf("Log starting date: %4d-JULY-01\n",year);
            break;
        case 8:
            printf("Log starting date: %4d-AUG-01\n",year);
            break;
        case 9:
            printf("Log starting date: %4d-SEP-01\n",year);
            break;
        case 10:
            printf("Log starting date: %4d-OCT-01\n",year);
            break;
        case 11:
            printf("Log starting date: %4d-NOV-01\n",year);
            break;
        case 12:
            printf("Log starting date: %4d-DEC-01\n",year);
            break;
    }

    return 0;
}
