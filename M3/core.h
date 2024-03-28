/*
*****************************************************************************
                        Assignment 1 - Milestone 2

Full Name  :Mehrnoosh Sarang
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
void clearInputBuffer(void);

void suspend(void);

int inputInt (void );

int inputIntPositive (void);

int inputIntRange (int lowerBand, int upperBand);

char inputCharOption ( const char str [] );

void inputCString (char* str, int minimumLen, int maximumLen);

void inputCStringNumbers(char* str, int minChar, int maxChar);


void displayFormattedPhone ( const char* str);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
