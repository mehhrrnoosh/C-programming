/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :mehrnoosh sarang
Student ID#:128498227
Email      :msarang@myseneca.ca
Section    :ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>
//#include "core.h"
#include <ctype.h>
#include <string.h>
#include "clinic.h"


//Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {

        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue void suspend(void)
void suspend (void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This is a function called inputInt() that prompts the user to input an integer and checks if the input is valid
int inputInt (void )
{
    int valid; //setting flag
    int user_input; //user variable
    char character = ' ';

    do { //a do-while loop to keep asking the user for input until a valid integer is provided.
        valid=1;
        scanf ("%d%c",&user_input,&character); //getting input from user

        if (character != '\n') //f the user inputs something other than a whole number, the function clears the input buffer and prompts the user to enter a whole number.
        {

            clearInputBuffer (); //clear buffer

            printf("Error! Input a whole number: ");
            valid=0;

        }
    }while (!valid);
    return user_input; //The function returns the valid integer entered by the user.
}


//this function prompts the user to input a positive integer and returns the validated input.
int inputIntPositive (void )
{
    int number;
    char character= ' ';
    int valid;

    do
    {
        valid =1; //It uses a do-while loop and scanf to read in the user input, and checks for two types of errors
        scanf ("%d%c",&number,&character);

        if (character != '\n') //If the input is not a whole number, the function clears the input buffer and prompts the user to input a whole number again.
        {
            clearInputBuffer ();
            printf("Error! Input a whole number: ");
        }
        if  (number <=0)
        {
            printf ("ERROR! Value must be > 0: "); //f the input is not positive, it prompts the user to input a positive integer again.
            valid=0;
        }
    }while (!valid);
    return number;
}



//This function takes two integer parameters representing the lower and upper bounds of an integer range.
int inputIntRange (int lowerBand, int upperBand)
{
    int number;
    int flag;
    do
    {
        flag=1;
        number = inputInt(); //prompts the user to input an integer using another function called inputInt().

        if (number < lowerBand || number > upperBand)
        {
            printf ("ERROR! Value must be between %d and %d inclusive: ",lowerBand,upperBand);
            flag=0;
        }
        else {
            flag=1; //The variable "flag" is used as a control flag to indicate whether the input is within the specified range.
        }

    }while(!flag);

    return number;
}

//The function inputCharOption takes in a character array str and prompts the user to enter a character
char inputCharOption ( const char str [] )
{
    char userInput; //declares a variable to store the user's input character.
    int i, flag; //declares two loop control variables and a flag variable to control the loop.
    int charCounter=0; //initializes a counter to 0 to count the number of valid characters.

    do {
        flag = 1;
        scanf(" %c", &userInput); //reads a character from the user input, ignoring any leading whitespace.
        for (i = 0; i < strlen(str); i++){ // use strlen() to get the length of the string
            if (userInput == str[i]) {
                charCounter++;
            }
        }
        if (charCounter == 0) { //no valid character is found
            printf("ERROR: Character must be one of [%s]: ", str);
            flag = 0;

        }
    }while (!flag);
    clearInputBuffer ();//clears the input buffer and returns the valid character.
    return userInput;
}


void inputCString(char* str, int minimumLen, int maximumLen) {
    int flag; // a flag to keep track of whether the input is valid
    int len; // the length of the input string
    char localStr[1000] = {0}; // a local string to store the user input

    do {
        flag = 1; // assume the input is valid
        scanf("%[^\n]%*c", localStr); // read the user input until a newline character is encountered
        len = strlen(localStr); // get the length of the user input

        if (len < minimumLen) { // if the length of the user input is less than the minimum required length
            printf("Your string is too short, please enter at least %d characters: ", minimumLen); // print an error message
            flag = 0; // set the flag to indicate that the input is invalid
        } else if (len > maximumLen) { // if the length of the user input is greater than the maximum allowed length
            printf("Your string is too long, please enter at most %d characters: ", maximumLen); // print an error message
            flag = 0; // set the flag to indicate that the input is invalid
        } else { // if the user input is within the required length range
            strcpy(str, localStr); // copy the user input to the output string
        }

    } while (!flag); // repeat the loop until the input is valid
}



void displayFormattedPhone ( const char* str) //This function takes a string as input, assumes it represents a phone number, and then formats it as (xxx)xxx-xxxx.
{
    int i = 0;
    int len = 0;

// Loop through the input string and count the number of digits
    while (str != NULL && str[len] && isdigit(str[len]) ) {
        len++;
    }

// If the length of the phone number is 10, format it
    if (len == 10) {
        printf("(");
        while (i < 3) {
            printf("%c", str[i]);
            i++;
        }

        printf(")");
        while (i < 6) {
            printf("%c", str[i]);
            i++;
        }

        printf("-");
        while (i < 10) {
            printf("%c", str[i]);
            i++;
        }
    } else
    {
        // If the length of the phone number is not 10, print a default formatted string
        printf("(___)___-____");
    }
// Count the length of the input string, if it is not null
    if (str != 0)
    {
        for (i = 0; str[i] != '\0'; i++)
            len++;

    }
}
