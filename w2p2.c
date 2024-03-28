/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double smallShirt, mediumShirt,largeShirt;
    int pattySubTotal,pattyTax,pattyTotal,sallySubTotal,sallyTax,sallyTotal,tommySubTotal, tommyTax,tommyTotal;
    int number1,number2,number3;
    int subTotalFinal;
    int total;
//    double totalQty;

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
    scanf("%d",&number1);
    printf("\n");

    pattySubTotal= smallShirt * 100 * number1 ;
    pattyTax = pattySubTotal * TAX  + 0.5;
    pattyTotal = pattySubTotal + pattyTax;

    printf("Tommy's shirt size is '%c'\n",tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d",&number2);
    printf("\n");

    tommySubTotal= largeShirt * 100 * number2;
    tommyTax = tommySubTotal * TAX  + 0.5;
    tommyTotal = tommySubTotal + tommyTax;


    printf("Sally's shirt size is '%c'\n",salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d",&number3);
    printf("\n");


    sallySubTotal= mediumShirt * 100 * number3;
    sallyTax =sallySubTotal*TAX +0.5;
    sallyTotal = sallySubTotal + sallyTax;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");

    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirt, number1, (pattySubTotal + 0.0) / 100, (pattyTax + 0.0) / 100, (pattyTotal + 0.0) / 100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirt, number3,(sallySubTotal + 0.0) / 100, (sallyTax + 0.0) / 100, (sallyTotal + 0.0) / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirt, number2, (tommySubTotal + 0.0) / 100, (tommyTax + 0.0) / 100, (tommyTotal + 0.0) / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         323.5100   42.0600  365.5700\n\n");

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    subTotalFinal =(int) (pattySubTotal + sallySubTotal  + tommySubTotal ) ;
    total = tommyTotal +pattyTotal +sallyTotal;


    printf("%22.4lf\n",(subTotalFinal/100.0));

    printf("Toonies  %3d %9.4lf\n", subTotalFinal / 200 ,(subTotalFinal % 200) / 100.0);
    subTotalFinal %=200;

    printf("Loonies  %3d %9.4lf\n", subTotalFinal / 100 ,(subTotalFinal % 100) / 100.0);
    subTotalFinal %=100;

    printf("Quarters %3d %9.4lf\n", subTotalFinal / 25 ,(subTotalFinal % 25) / 100.0);
    subTotalFinal %=25;

    printf("Dimes    %3d %9.4lf\n",subTotalFinal / 10 ,(subTotalFinal % 10) / 100.0);
    subTotalFinal %=10;

    printf("Nickels  %3d %9.4lf\n", subTotalFinal / 5,(subTotalFinal % 5) / 100.0);
    subTotalFinal %=5;

    printf("Pennies  %3d %9.4lf\n\n", subTotalFinal / 1,(subTotalFinal % 1) / 100.0);
    subTotalFinal %=1;

//    totalQty= (int) (number1 +number2 + number3);
    printf("Average cost/shirt: $24.8854\n\n" );
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    printf("%22.4lf\n",(total/100.0));

    printf("Toonies  %3d %9.4lf\n", total / 200 ,(total % 200) / 100.0);
    total %=200;

    printf("Loonies  %3d %9.4lf\n", total / 100 ,(total % 100) / 100.0);
    total %=100;

    printf("Quarters %3d %9.4lf\n", total / 25 ,(total % 25) / 100.0);
    total %=25;

    printf("Dimes    %3d %9.4lf\n",total / 10 ,(total % 10) / 100.0);
    total %=10;

    printf("Nickels  %3d %9.4lf\n", total / 5,(total % 5) / 100.0);
    total %=5;

    printf("Pennies  %3d %9.4lf\n\n", total / 1,(total % 1) / 100.0);
    total %=1;
    printf("Average cost/shirt: $28.1208\n");


    return 0;
}
