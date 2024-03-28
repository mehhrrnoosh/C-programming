/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    double smallShirt, mediumShirt,largeShirt;
    int subTotal,taxCal,total;
    int number;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf",&smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf",&mediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf",&largeShirt);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n",smallShirt);
    printf("MEDIUM : $%.2lf\n",mediumShirt);
    printf("LARGE  : $%.2lf\n\n",largeShirt);
    printf("Patty's shirt size is '%c'\n",patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d",&number);
    printf("\n");

    subTotal = smallShirt *100*number;
    taxCal=subTotal*TAX +0.5;
    total=subTotal+taxCal;

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n",number);
    printf("Sub-total: $%8.4lf\n",(double )subTotal /100);
    printf("Taxes    : $%8.4lf\n",(double )taxCal/100);
    printf("Total    : $%8.4lf\n",(double )total/100);
    return 0;
}
