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
// SORTING VALUES FUNCTIONS
/////////////////////////////////////
void sortAppointments(struct Appointment appoints[], int max) {
    int i, j;
    struct Appointment temp;

    // Convert all dates and times to minutes for comparison
    for (i = 0; i < max; i++) {
        int totalMinutes = appoints[i].date.year * 12 * 30 * 24 * 60
            + appoints[i].date.month * 30 * 24 * 60
            + appoints[i].date.day * 24 * 60
            + appoints[i].time.hour * 60
            + appoints[i].time.min;
        appoints[i].time.min = totalMinutes;
    }

    // Sort the appointments using bubble sort
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++) {
            if (appoints[j].time.min > appoints[j + 1].time.min) {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Convert back to date and time format
    for (i = 0; i < max; i++) {
        int totalMinutes = appoints[i].time.min;
        appoints[i].date.year = totalMinutes / (12 * 30 * 24 * 60);
        totalMinutes %= 12 * 30 * 24 * 60;
        appoints[i].date.month = totalMinutes / (30 * 24 * 60);
        totalMinutes %= 30 * 24 * 60;
        appoints[i].date.day = totalMinutes / (24 * 60);
        totalMinutes %= 24 * 60;
        appoints[i].time.hour = totalMinutes / 60;
        appoints[i].time.min = totalMinutes % 60;
    }
}

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}
// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) { //an array of patient structures that contain the patient data to be displayed.
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

        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        selection = inputIntRange(0, 2); // call this function to get the number in this range and store in the variable

        printf("\n");

        if (selection == 1) //if this selected call the searchPatientByPatientNumber function
        {
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();

        }
        else if (selection == 2) // if this selected the searchPatientByPhoneNumber function
        {
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();

        }

    } while (selection != 0); //loop until the selection is not zero
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

    }
    else { //f there is an empty slot, it assigns the next available patient number to the new record and prompts the user to input the details of the new patient.
        patient[index].patientNumber = nextPatientNumber(patient, max); //assign  number to the element at the new index
        inputPatient(&patient[index]); //getting new records
        printf("*** New patient record added ***\n\n");

    }
}
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int patientNumber, index;
    printf("Enter the patient number: ");
    patientNumber = inputInt();
    printf("\n");

    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
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
void removePatient(struct Patient patient[], int max) {
    int pNumber, index;
    char choice, ch;
    printf("Enter the patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");

        int flag = 1;

        do {
            scanf(" %c%c", &choice, &ch);

            if ((choice == 'n' || choice == 'N') && (ch == '\n')) {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }
            else if ((choice == 'y' || choice == 'Y') && (ch == '\n')) {
                // Assigning patient to safe empty state so that the other function can't access it
                patient[index].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }
            else {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (flag);
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;

    sortAppointments(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(NULL, 1);

    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber){
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int Days = 31;
    int i, j;
    struct Date date;

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        Days = 30;
    }
    if (date.month == 2)
    {
        Days = 28;
    }
    if (date.year % 4 == 0 && date.month == 2)
    {
        Days = 29;
    }
    printf("%d)  : ", Days);
    date.day = inputIntRange(1, Days);
    printf("\n");

    sortAppointments(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&date, 0);
  
    // loop through all appointments
    for (i = 0; i < data->maxAppointments; i++)
    {
        // check if the appointment date matches the given date
        if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
        {
            // loop through all patients to find the one associated with the current appointment
            for (j = 0; j < data->maxAppointments; j++)
            {
                // check if the patient number matches the one associated with the current appointment
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    // display the schedule data for the patient and appointment
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }    printf("\n");

}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct  Appointment* app, int maxAppointments, struct Patient* pt, int patientCapacity)
{
    int Days = 31;
    int patient_number, i, slot = 1;
    struct Date date;
    struct Time time;


    printf("Patient Number: ");
    patient_number = inputIntPositive();

    i = findPatientIndexByPatientNum(patient_number, pt, patientCapacity);

    if (i >= 0) {
        do {
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            // Taking the day as input
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11) {
                Days = 30;
            }
            if (date.month == 2) {
                Days = 28;
            }
            if (date.year % 4 == 0 && date.month == 2) {
                Days = 29;
            }

            printf("%d)  : ", Days);
            date.day = inputIntRange(1, Days);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            if (isTimeSlotAvailable(date, time, app, maxAppointments)) {
                printf("\nERROR: Appointment timeslot is not available!\n");
                printf("\n");
            }
            else {
                do {
                    if ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0)) {
                        printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                        printf("Hour (0-23)  : ");
                        time.hour = inputIntRange(0, 23);
                        printf("Minute (0-59): ");
                        time.min = inputIntRange(0, 59);
                    }
                    else {
                        slot = 0;
                    }
                } while (slot);
            }
        } while (slot);

        i = getFirstAvailableSlot(app, maxAppointments);
        app[i].date = date;
        app[i].time = time;
        app[i].patientNumber = patient_number;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }

}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int patientCapacity) {
    int i;
    int patient_number;
    int Days = 0;
    int appointment_index;
    struct Date date;

    printf("Patient Number: ");
    patient_number = inputIntPositive();
    i = findPatientIndexByPatientNum(patient_number, pt, patientCapacity);

    if (i >= 0) {
        printf("Year        : ");
        date.year = inputIntPositive();

        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11) {
            Days = 30;
        }
        if (date.month == 2) {
            Days = 28;
        }
        if (date.year % 4 == 0 || date.month == 2) {
            Days = 29;
        }
        printf("%d)  : ", Days);
        date.day = inputIntRange(1, Days);
        appointment_index = isAppointmentValid(patient_number, date, app, maxAppointments);

        if (appointment_index >= 0) {
            printf("\n");

            displayPatientData(&pt[i], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y') {
                app[appointment_index].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
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
    number = inputInt(); //call the inputInt to return the value to the variable number

    putchar('\n');

    index = findPatientIndexByPatientNum(number, patient, max);

    if (index != -1)

    {
        displayPatientData(&patient[index], FMT_FORM); //display the record to the user in "form" format

    }
    else {
        printf("*** No records found ***\n");
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0;
    int count = 0;
    char searched_Phone[11] = { 0 };

    printf("Search by phone number: ");//user must be prompted for the unique patient number

    inputCString(searched_Phone, PHONE_LEN, PHONE_LEN); // call inputCstring get the string by defined length;
    putchar('\n');

    displayPatientTableHeader(); //call this function if the record found

    for (i = 0; i < max; i++)
    {

        if (strcmp(searched_Phone, patient[i].phone.number) == 0) //The strcmp function compares two strings and returns 0 if they are equal,
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++; //in case of finding record increase the counter to one
        }
    }

    if (count == 0) //if there is no match
    {
        printf("\n*** No records found ***");
        printf("\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)


int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0;
    int largestNumber = patient[i].patientNumber;
    int nextNumber;

    for (i = 0; i < max; i++) //looping
    {
        if (patient[i].patientNumber > largestNumber) { //if the largestNumber is less than the function variable
            largestNumber = patient[i].patientNumber; //store into the larestNumber
        }
    }

    nextNumber = largestNumber + 1;
    return nextNumber; //returning back the next number
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    int index = -1;
    for (i = 0; i < max && index == -1; i++) {
        if (patient[i].patientNumber == patientNumber) //the record is found
        {
            index = i;  //the position of the matched element is  returned.
        }
    }
    return index; //record is not found then return the index
}

int isTimeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int  maxAppointments)
{
    int i;
    int slot = 0;

    for (i = 0; i < maxAppointments; i++)
    {
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min)
        {
            slot = 1;
        }

    }
    return slot;
}

//This function determines the next available time slot and returns its index.
int getFirstAvailableSlot(struct Appointment* app, int maxAppointments) {
    int i = 0;
    int isAvailable = 0;
    while (isAvailable == 0 && i < maxAppointments)
    {

        if (app[i].patientNumber < 1) {
            isAvailable = 1;
        }
    }
    return i;
}

//This function checks whether an appointment is valid or not.
int isAppointmentValid(int patientNumber, struct Date date, struct Appointment* appointments, int maxAppointments) {
    int i = 0;
    while (i < maxAppointments &&
        !(appointments[i].patientNumber == patientNumber &&
            appointments[i].date.day == date.day &&
            appointments[i].date.month == date.month &&
            appointments[i].date.year == date.year)) {
        i++;
    }
    return i == maxAppointments ? -1 : i;
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
    char number[PHONE_LEN + 1];

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
        phone->number[0] = 0;
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
        printf("Contact: %s\n", phone->description); //Display the contact number
        printf("Number : "); //prompt user to enter the Name
        inputCStringNumbers(number, 10, 10);
        strcpy(phone->number, number);
        printf("\n");
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////
// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {

    int i = 0;
    int isEndOfFile = 0;

    // Opening the file
    FILE* fp;
    fp = fopen(datafile, "r");

    // Checking for null pointer
    if (fp != NULL) {
        while (!isEndOfFile && i < max) {
            if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
                patients[i].name,
                patients[i].phone.description,
                patients[i].phone.number) != EOF)
            {
                i++;
            }
            else {
                isEndOfFile = 1;
            }
        }

        // Closing the file
        fclose(fp);
    }
    else {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return i;
}
// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    int i = 0;
    int isEndOfFile = 0;
    int count = 0;

    // Opening the file
    FILE* fp;
    fp = fopen(datafile, "r");

    // Checking for null pointer
    if (fp != NULL) {

        // Iterating until file reaches the end of file or the max is reached
        for (i = 0; i < max && !isEndOfFile; i++) {
            // Reading values from file and storing them
            if (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year,
                &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) !=
                EOF) {

                // Incrementing count if the end of file is not reached
                count++;
            }
            else {
                isEndOfFile = 1;
            }
        }

        // Closing the file
        fclose(fp);
    }
    else {
        printf("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return count;
}
