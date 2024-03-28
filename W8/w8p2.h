/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Mehrnoosh sarang
Student ID#: 128498227
Email      : msarang@mysenecaca.
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


// ----------------------------------------------------------------------------
// defines/macros
#define CONVERSION_FACTOR 2.20462
#define MAX_NO_PR 3
#define KG_METRIC_UNIT 2.20462
#define GRAM_NO   64

// ----------------------------------------------------------------------------
// structures

struct ReportData
{
    int skuNumber;
    double productPrice;
    int calories;
    double lbsWeight;
    double kgWeight;
    int gWeight;
    double totalServing;
    double servingCost;
    double caloriesCost;
};

   struct CatFoodInfo
   {
       int sku;
       double product_Price;
       int calories;
       double weigh;
   };
   // ----------------------------------------------------------------------------
   // function prototypes
// ----------------------------------------------------------------------------
// PART-1

   // 1. Get user input of int type and validate for a positive non-zero number
   //    (return the number while also assigning it to the pointer argument)
   int getIntPositive (int* ptrInt);

   // 2. Get user input of double type and validate for a positive non-zero number
   //    (return the number while also assigning it to the pointer argument)
   double getDoublePositive (double* ptrDouble);


   // 3. Opening Message (include the number of products that need entering)
   void openingMessage (const int productNumber);


   // 4. Get user input for the details of cat food product
   struct CatFoodInfo getCatFoodInfo (const int sequenceNumber);

   // 5. Display the formatted table header
   void  displayCatFoodHeader (void );


   // 6. Display a formatted record of cat food data
   void displayCatFoodData (const int sku,const double* productPrice,const int calories, const double* weigh);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
   double convertLbsKg (const double* weight,double* kgConversionResult);

// 9. convert lbs: g
   int convertLbsG (const double* weight,int* gConversionResult);

// 10. convert lbs: kg / g
   void convertLbs (const double* weight,double* kgConversionResult,int* gConversionResult );

// 11. calculate: servings based on gPerServ
    double calculateServings (const int servingSizeGram,const int totalGram,double* servingResult );

// 12. calculate: cost per serving
double calculateCostPerServing (const double* prodcutPrice,const double* servingResult,double* costPerserving);

// 13. calculate: cost per calorie
    double calculateCostPerCal (const double* productPrice, const double* calories, double* calorieResult);

// 14. Derive a reporting detail record based on the cat food product data
   struct ReportData calculateReportData (const struct CatFoodInfo catFoodInfo);
    

// 15. Display the formatted table header for the analysis results
    void displayReportHeader (void);
    
// 16. Display the formatted data row in the analysis table
    void displayReportData (const struct ReportData reportData, const int record);

// 17. Display the findings (cheapest)
   void displayFinalAnalysis (const struct CatFoodInfo);

// 7. Logic entry point
    void start(void );
// ---------------------------------------------------------------------------
