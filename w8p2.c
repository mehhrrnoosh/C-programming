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
#include  "w8p2.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int* ptrInt)
{
    int userInput;
    int flag;
    do {

        flag = 1;
        scanf("%d", &userInput);
        if (userInput <= 0) {
            printf("ERROR: Enter a positive value: ");
            flag=0;
        }
    } while (!flag);
    if (ptrInt != NULL) {
        *ptrInt = userInput;

    }
    return userInput;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double* ptrDouble)
{
    double userInput;
    int flag;
    do {

        flag = 1;
        scanf("%lf", &userInput);
        if (userInput <= 0) {
            printf("ERROR: Enter a positive value: ");
            flag=0;
        }
    } while (!flag);
    if (ptrDouble != NULL) {
        *ptrDouble = userInput;
    }
    return userInput;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int productNumber)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n",productNumber);
    printf("NOTE: A 'serving' is %dg\n",GRAM_NO);

}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)
{
    struct CatFoodInfo catFoodInfo;

    printf("\nCat Food Product #%d\n", sequenceNumber);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&catFoodInfo.sku);

    printf("PRICE         : $");
    getDoublePositive(&catFoodInfo.product_Price);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&catFoodInfo.weigh);

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
void displayCatFoodData (const int sku,const double* productPrice,const int calories, const double* weigh)
{
    printf("%07d %10.2lf %10.1lf %8d\n",sku,*productPrice,*weigh,calories);
}


// 7. Logic entry point
//void start(void ) {
//    int i;
//    struct CatFoodInfo foodForCat[MAX_NO_PR] = {{}};
//    openingMessage(MAX_NO_PR);
//
//    for (i = 0; i < MAX_NO_PR; i++) {
//        foodForCat[i] = getCatFoodInfo(i);
//    }
//     displayCatFoodHeader();
//
//    for (i = 0; i < MAX_NO_PR; i++)
//    {
//        displayCatFoodData(foodForCat[i].sku, &foodForCat[i].productPrice, foodForCat[i].calories, &foodForCat[i].weigh);
//    }
//}
//


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg (const double* weight,double* kgConversionResult)
{
    double result;
    result = *weight/KG_METRIC_UNIT;
    if( kgConversionResult != NULL)
    {
        *kgConversionResult =result;

    }
    return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG (const double* weight,int* gConversionResult)
{
    int result;
    result =(int) (*weight/KG_METRIC_UNIT * 1000 );

    if(gConversionResult != NULL )
    {
        *gConversionResult = result;

    }
    return result;
}

// 10. convert lbs: kg and g


void convertLbs(const double* weight,double* kgConversionResult,int* gConversionResult )
{
//    double kgResult;
//    int gResult;

    convertLbsKg(weight,kgConversionResult);
    convertLbsG(weight,gConversionResult);
//
//    *kgConversionResult = kgResult;
//    *gConversionResult = gResult;

}

// 11. calculate: servings based on gPerServ
double calculateServings (const int servingSizeGram,const int totalGram,double* servingResult )
{
    double result ;
    result = ((double)totalGram / servingSizeGram);

    if (servingResult != NULL)
    {
        *servingResult= result;
    }
    return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing (const double* prodcutPrice,const double* servingResult,double* costPerserving)
{
    double result;
    result = *prodcutPrice / *servingResult ;

    if (costPerserving != NULL)
    {
        *costPerserving = result;

    }
    return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal (const double* productPrice, const double* calories, double* calorieResult)
{
    double result;
    result = *productPrice / *calories;

    if ( calorieResult != NULL)
    {
        *calorieResult = result;
    }
    return result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData (const struct CatFoodInfo catFoodInfo) {
    struct ReportData reportData;

    reportData.skuNumber = catFoodInfo.sku;
    reportData.calories = catFoodInfo.calories;
    reportData.lbsWeight = catFoodInfo.weigh;
    reportData.productPrice = catFoodInfo.product_Price;

    reportData.kgWeight = convertLbsKg(&catFoodInfo.weigh, &reportData.kgWeight);
    reportData.gWeight = convertLbsG(&catFoodInfo.weigh, &reportData.gWeight);
    reportData.totalServing = calculateServings(GRAM_NO, reportData.gWeight, &reportData.totalServing);
    reportData.servingCost = calculateCostPerServing(&catFoodInfo.product_Price, &reportData.totalServing,
                                                     &reportData.servingCost);
    double  calories = (catFoodInfo.calories * reportData.totalServing);

    reportData.caloriesCost = calculateCostPerCal(&reportData.productPrice, &calories,
                                                  &reportData.caloriesCost);
    return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader (void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", GRAM_NO);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData (const struct ReportData reportData, const int record) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
           reportData.skuNumber, reportData.productPrice,
           reportData.lbsWeight, reportData.kgWeight,
           reportData.gWeight, reportData.calories,
           reportData.totalServing,
           reportData.servingCost,
           reportData.caloriesCost);
//    if (record > 0) {
//        printf("***\n");
//    }
}
// 17. Display the findings (cheapest)

void displayFinalAnalysis (const struct CatFoodInfo catFoodInfo)
{
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n",catFoodInfo.sku, catFoodInfo.product_Price);
    printf("Happy shopping!\n");

}


// ----------------------------------------------------------------------------
void start(void ) {
    int i, cheapestPriceIndex;
    double cheapestPrice;


    struct ReportData reportData[MAX_NO_PR] = {{0}};
    struct CatFoodInfo foodItem[MAX_NO_PR] = {{0}};

    //opening message
    openingMessage(MAX_NO_PR);


    for (i = 0; i < MAX_NO_PR; i++) {
        foodItem[i] = getCatFoodInfo(i + 1);
        reportData[i] = calculateReportData(foodItem[i]);
    }

    //display catfood header
    displayCatFoodHeader();
    for (i = 0; i < MAX_NO_PR; i++) {
        displayCatFoodData(foodItem[i].sku, &foodItem[i].product_Price, foodItem[i].calories, &foodItem[i].weigh);


    }
    //finifng the cheapest product


    cheapestPrice =reportData [0].servingCost;
    for (i = 0; i < MAX_NO_PR; i++)
    {

//        reportData[i] = calculateReportData(foodItem[i]);
        if (reportData[i].caloriesCost <= cheapestPrice) {
            cheapestPrice = reportData[i].caloriesCost;
            cheapestPriceIndex = i;
        }
    }
    printf("\n");

    displayReportHeader();

    for (i = 0; i < MAX_NO_PR; i++) {
        displayReportData(reportData[i], cheapestPriceIndex);
        if (cheapestPriceIndex == i) {
            printf(" ***\n");
        } else
        {
            printf("\n");
        }

    }
    printf("\n");

    //final analyze

    for (i = 0; i < MAX_NO_PR; i++)
    {
        if (i == cheapestPriceIndex)
        {

            displayFinalAnalysis(foodItem[i]);
        }
    }

}









