/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char loopType;
    int  loopNumber,count;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopNumber);

        if (loopType == 'D') {
            if (loopNumber >= 3 && loopNumber <= 20) {
                count = 0;
                printf("DO-WHILE: ");
                do {
                    printf("%c", loopType);
                    count++;
                } while (count < loopNumber);
                putchar('\n');
            } else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        } else if (loopType == 'F') {
            if (loopNumber >= 3 && loopNumber <= 20) {
                printf("FOR     : ");
                for (count = 0; count < loopNumber; count++) {
                    printf("%c", loopType);
                }
                printf("\n");
            }else
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        } else if (loopType == 'W') {
            if (loopNumber >= 3 && loopNumber <= 20) {
                printf("WHILE   : ");
                count = 0;
                while (count < loopNumber) {
                    printf("%c", loopType);
                    count++;
                }
                putchar('\n');
            } else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        } else if (!(loopType == 'F' || loopType == 'D' || loopType == 'W' || loopType == 'Q')) {
            printf("ERROR: Invalid entered value(s)!\n");

        } else if (loopType == 'Q') {
            if (!(loopNumber == 0)) {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            } else {
                printf("\n+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
                printf("\n");
            }
        }

    } while (! (loopType == 'Q' && loopNumber ==0));

    return 0;
}
