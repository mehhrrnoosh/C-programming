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

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H
//#define char CHAR_OPTION []={0}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void); //This function clears the input buffer, which is useful when you need to get rid of any extra characters in the input stream.

void suspend(void);//This function suspends the program's execution for a period of time.

int inputInt (void );//This function reads an integer value from the user input

int inputIntPositive (void); //This function reads a positive integer value from the user input.

int inputIntRange (int lowerBand, int upperBand); //This function reads an integer value within a specified range from the user input.

char inputCharOption ( const char str [] ); //This function reads a character from the user input, and validates whether it is a valid option from a given set of characters

void inputCString (char* str, int minimumLen, int maximumLen); //This function reads a string of characters from the user input, ensuring that it meets a minimum and maximum length requirement

void displayFormattedPhone ( const char* str); //This function formats and displays a phone number in a specific format.



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
