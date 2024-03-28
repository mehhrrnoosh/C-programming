/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : Mehrnoosh Sarang
Student ID#: 128498227
Email      : msarang
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
// ----------------------------------------------------------------
// MACRO'S

#define MAX_NO_PR 3
#define GRAM_NO   64
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double product_Price;
    int calories;
    double weight;
};
// ----------------------------------------------------------------------------
// function prototypes


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int* ptrInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double* ptrDouble);


// 3. Opening Message (include the number of products that need entering)
void openingMessage (const int product_Number);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo (const int sequence_Number);

// 5. Display the formatted table header
void  displayCatFoodHeader (void );


// 6. Display a formatted record of cat food data
void displayCatFoodData (const int sku,const double* product_Price,const int calories, const double* weight);


// 7. Logic entry point
void start(void );
