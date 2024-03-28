/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2

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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h> //functions for manipulating strings in C.


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
            case 0:
                printf("Are you sure you want to exit? (y|n): ");
                selection = !(inputCharOption("yn") == 'y');
                putchar('\n');
                if (!selection)
                {
                    printf("Exiting system... Goodbye.\n\n");
                }
                break;
            case 1:
                menuPatient(data->patients, data->maxPatient);
                break;
            case 2:
                printf("<<< Feature not yet available >>>\n\n");
                break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
            case 1:
                displayAllPatients(patient, max, FMT_TABLE);
                suspend();
                break;
            case 2:
                searchPatientData(patient, max);
                break;
            case 3:
                addPatient(patient, max);
                suspend();
                break;
            case 4:
                editPatient(patient, max);
                break;
            case 5:
                removePatient(patient, max);
                suspend();
                break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) { //n array of patient structures that contain the patient data to be displayed.
    int i;
    int valid = 0;

    if (fmt == FMT_TABLE) { //The function first checks if the format is FMT_TABLE, and if so, it calls the function displayPatientTableHeader() to print a header for the patient data table.


        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++) {  // iterates through each patient in the array, checking if the patient number is not zero.
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt); //f the patient number is not zero, it calls the function displayPatientData() to display the patient's data in the specified format.
            valid = 1;
        }
    }
    if (!valid) {
        printf("*** No records found ***\n\n");
    }
    putchar('\n');
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) //This is a function that allows the user to search for patient data based on either patient number or phone number.
{
    int selection;

    do {
//
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        selection=inputIntRange(0, 2); // call this function to get the number in this range and store in the variable

        printf("\n");

        if  (selection == 1) //if this selected call the searchPatientByPatientNumber function
        {
            searchPatientByPatientNumber( patient,  max);
            putchar('\n');
            suspend();

        }else if (selection ==2) // if this selected the searchPatientByPhoneNumber function
        {
            searchPatientByPhoneNumber( patient,  max);
            putchar('\n');
            suspend();

        }

    } while (selection !=0); //loop until the selection is not zero
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) { //This is a function that adds a new patient record to the patient array.

        int i, index = -1;
        for (i = 0; i < max && index == -1; i++) { //The function iterates over the array to find the first empty slot to add the new record to.
            if (patient[i].patientNumber == 0) {
                index = i;
            }
        }
        if (index == -1) //record is not found
        {
            printf("ERROR: Patient listing is FULL!\n\n");

        } else { //f there is an empty slot, it assigns the next available patient number to the new record and prompts the user to input the details of the new patient.
            patient[index].patientNumber = nextPatientNumber(patient,max); //assign  number to the element at the new index
            inputPatient(&patient[index]); //getting new records
            printf("*** New patient record added ***\n\n");

        }
    }
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int patientNumber,index;
    printf("Enter the patient number: ");
    patientNumber =inputInt();
    printf("\n");

    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if(index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[index]); //call menuPatientEdit to edit the record
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) { //removing patient function
    int unique_number;
    int index;
    int answer;

    printf("Enter the patient number: "); // Prompts the user to enter a patient number, finds the index of the corresponding


    unique_number = inputInt(); // call the inputInt to get the number store in the variable
    index = findPatientIndexByPatientNum( unique_number,patient, max); //finding detemined index

    if( index == -1) //check if the index is found

    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else {
        putchar('\n');
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        answer = inputCharOption("yn"); // validates the input and returns the character entered by the user.

        if (answer == 'n' || answer == 'N') //check if the answer is n or N
        {
            printf("Operation aborted.\n\n"); //display this error

        } else {

            patient[index].patientNumber = 0;
            printf("Patient record has been removed!");
            printf("\n\n");

        }
    }

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
        int number;
        int index;

        printf("Search by patient number: "); //user must be prompted for the unique patient number:
        number=inputInt(); //call the inputInt to return the value to the variable number

        putchar('\n');

        index = findPatientIndexByPatientNum( number,patient, max);

        if( index!= -1)

        {
            displayPatientData(&patient[index], FMT_FORM); //display the record to the user in "form" format

        }else {
            printf("*** No records found ***\n");
        }
    }


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i=0;
    int count=0;
    char searched_Phone [11]={0};

    printf("Search by phone number: ");//user must be prompted for the unique patient number

    inputCString(searched_Phone, PHONE_LEN, PHONE_LEN); // call inputCstring get the string by defined length;
    putchar('\n');

    displayPatientTableHeader(); //call this function if the record found

    for(i=0; i<max; i++)
    {

        if (strcmp(searched_Phone,patient[i].phone.number) == 0 ) //The strcmp function compares two strings and returns 0 if they are equal,
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++; //in case of finding record increase the counter to one
        }
    }

    if(count == 0 ) //if there is no match
    {
        printf("\n*** No records found ***");
        printf("\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


int nextPatientNumber(const struct Patient patient[], int max)
{
    int i=0;
    int largestNumber = patient[i].patientNumber;
    int nextNumber;

    for (i =0; i <max; i++) //looping
    {
        if(patient[i].patientNumber > largestNumber){ //if the largestNumber is less than the function variable
            largestNumber = patient[i].patientNumber; //store into the larestNumber
        }
    }

    nextNumber = largestNumber +1;
    return nextNumber; //returning back the next number
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,const struct Patient patient[], int max)
{
    int i;
    int index=-1;
    for (i=0; i<max && index==-1 ;i++) {
        if (patient[i].patientNumber == patientNumber) //the record is found
        {
            index = i;  //the position of the matched element is  returned.
        }
    }
    return index; //record is not found then return the index
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{

    printf("Patient Data Input\n"
           "------------------\n"
           "Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN); //get the string from inputCstring with the specific lenght
    printf("\n");

    inputPhoneData(&patient->phone); //call inputPhoneData to show the phone number

}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    selection = inputIntRange(1, 4);

    putchar('\n');

    if (selection == 4)
    {
        strcpy(phone->description, "TBD");
        phone->number[0] =0;
    }
    else
    {
        if (selection == 1)
        {
            strcpy(phone->description, "CELL");
        }
        if (selection == 2)
        {
            strcpy(phone->description, "HOME");
        }
        if (selection == 3)
        {
            strcpy(phone->description, "WORK");
        }
        printf("Contact: %s\n",phone->description); //Display the contact number
        printf("Number : "); //prompt user to enter the Name
        inputCString(phone->number, 10, 10);
        printf("\n");
    }
}

