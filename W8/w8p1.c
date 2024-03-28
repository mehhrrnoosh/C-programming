/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  :Mehrnoosh sarang
Student ID#:128498227
Email      :msarang@myseneca.ca
Section    :ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries

#include  <stdio.h>
// User Libraries
#include  "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int* ptrInt)
{
    int user_Iput;
    int valid;
    do {

        valid = 1;
        scanf("%d", &user_Iput);
        if (user_Iput <= 0) {
            printf("ERROR: Enter a positive value: ");
            valid=0;
        }
    } while (!valid);
    if (ptrInt != NULL) {
        *ptrInt = user_Iput;

    }
    return user_Iput;
}



// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double* ptrDouble)
{
    double user_Input;
    int valid;
    do {

        valid = 1;
        scanf("%lf", &user_Input);
        if (user_Input <= 0) {
            printf("ERROR: Enter a positive value: ");
            valid=0;
        }
    } while (!valid);
    if (ptrDouble != NULL) {
        *ptrDouble = user_Input;
    }
    return user_Input;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int product_Number)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n",product_Number);
    printf("NOTE: A 'serving' is %dg\n",GRAM_NO);

}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_Number) {
    struct CatFoodInfo catFoodInfo;
    printf("\nCat Food Product #%d\n", sequence_Number+1);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&catFoodInfo.sku);

    printf("PRICE         : $");
    getDoublePositive(&catFoodInfo.product_Price);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&catFoodInfo.weight);

    printf("CALORIES/SERV.: ");
    getIntPositive(&catFoodInfo.calories);

    return catFoodInfo;
}
// 5. Display the formatted table header
void  displayCatFoodHeader (void )
{
    printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");

}

// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku,const double* product_Price,const int calories, const double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n",sku,*product_Price,*weight,calories);
}


// 7. Logic entry point
void start(void ) {
    int i;
    struct CatFoodInfo foodForCat[MAX_NO_PR] = {{}};
    openingMessage(MAX_NO_PR);

    for (i = 0; i < MAX_NO_PR; i++) {
        foodForCat[i] = getCatFoodInfo(i);
    }
    displayCatFoodHeader();

    for (i = 0; i < MAX_NO_PR; i++)
    {
        displayCatFoodData(foodForCat[i].sku, &foodForCat[i].product_Price, foodForCat[i].calories, &foodForCat[i].weight);
    }
}

//void start (void)
