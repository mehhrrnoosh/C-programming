/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  :Mehrnoosh Sarang
Student ID#:128498227
Email      :msarang@myseneca.ca
Section    :ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    char type1, type2, type3;
//    char size1, size2, size3;
    int weight1, weight2, weight3;
    char cream1, cream2, cream3;
 ;
    char coffeStrenght, coffe_with_cream;
    int dailyServing;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
//
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n");

    printf("---+------------------------+---------------+-------+\n"
           "   |    Coffee              |   Packaged    | Best  |\n"
           "   |     Type               |  Bag Weight   | Served|\n"
           "   +------------------------+---------------+ With  |\n"
           "ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n"
           "---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           (type1 == 'l' || type1 == 'L'), (type1 == 'm' || type1 == 'M'),(type1 == 'R' || type1 == 'r'),
            weight1, weight1/ GRAMS_IN_LBS,
           (cream1 == 'Y' || cream1 == 'y'));
//
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           (type2 == 'l' || type2 == 'L'), (type2 == 'm' || type2 == 'M'),(type2 == 'R' || type2 == 'r'),
           weight2, weight2/ GRAMS_IN_LBS,
           (cream1 == 'n' || cream1 == 'n'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           (type3 == 'l' || type3 == 'L'), (type3 == 'm' || type3 == 'M'),(type3 == 'R' || type3 == 'r'),
           weight3, weight3/ GRAMS_IN_LBS,
           (cream3 == 'Y' || cream3 == 'y'));

    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n"
           "Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c",&coffeStrenght);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c",&coffe_with_cream);

    printf("Typical number of daily servings: ");
    scanf("%d",&dailyServing);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n"
           "  |     Coffee      |  Packaged   | With  |\n"
           "ID|      Type       | Bag Weight  | Cream |\n"
           "--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'L' || coffeStrenght =='l') && ( type1 == 'l' || type1 == 'L'),
           (weight1=250) && ( dailyServing >=1  && dailyServing <= 4),
           (cream1 == 'y' || cream1 =='Y') && (coffe_with_cream =='y' || coffe_with_cream =='Y'));

    printf(" 2|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'L' || coffeStrenght =='l') && ( type2 == 'l' || type2 == 'l'),
           (weight1=500) && ( dailyServing >=5  && dailyServing <= 9),
           (cream2 == 'N' || cream2 =='n') && (coffe_with_cream =='n' || coffe_with_cream =='N'));

    printf(" 3|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'L' || coffeStrenght =='l') && ( type3 == 'l' || type3 == 'L'),
           (weight3=1000) && ( dailyServing >=10),
           (cream3 == 'n' || cream3 =='N') && (coffe_with_cream =='n' || coffe_with_cream =='N'));

    printf("\nEnter how you like your coffee...\n\n");
     printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeStrenght);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffe_with_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServing);
      printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");


    printf("--------------------+-------------+-------+\n"
           "  |     Coffee      |  Packaged   | With  |\n"
           "ID|      Type       | Bag Weight  | Cream |\n"
           "--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'L' || coffeStrenght =='l') && ( type1 == 'm' || type1 == 'M'),
           (weight1=250) && ( dailyServing >=1  && dailyServing <= 4),
           (cream1 == 'n' || cream1 =='N') && (coffe_with_cream =='y' || coffe_with_cream =='Y'));

    printf(" 2|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'L' || coffeStrenght =='l') && ( type2 == 'l' || type2 == 'l'),
           (weight1=500) && ( dailyServing >=5  && dailyServing <= 9),
           (cream2 == 'n' || cream2 =='N') && (coffe_with_cream =='n' || coffe_with_cream =='N'));

    printf(" 3|       %d         |      %d      |   %d   |\n",
           (coffeStrenght == 'm' || coffeStrenght =='M') && ( type3 == 'm' || type3 == 'M'),
           (weight3=1000) && ( dailyServing >=10),
           (cream3 == 'n' || cream3 =='N') && (coffe_with_cream =='n' || coffe_with_cream =='N'));

    printf("\nHope you found a product that suits your likes!\n\n");

    return 0;
}

