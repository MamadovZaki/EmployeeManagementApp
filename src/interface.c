#include "../include/utils.h"
#include "../include/interface.h"

void DisplayProgramInterface()
{
    /* displays options to the user to choose from */
    printf("1. Add a Record\n"
           "2. List a Record\n"
           "3. Modify a Record\n"
           "4. Delete a Record\n"
           "5. Exit\n");
}

void generateRecord(Employee **X)
{
    /*********************************************
     * Description:
     *************** 
     *  takes employee info and save it to a file
     
     * Output: 
     ***********
     * 1 when Employee record is saved successfully
     * 0 if process failed
     **********************************************/
    int status;
    char buffer[50];
    *X = malloc(sizeof(Employee));
    if (*X != NULL)
    {
        (*X)->firstName = input_str("First Name: ");
        (*X)->lastName = input_str("Last Name: ");
        (*X)->age = input_str("Age: ");
        (*X)->basic_salary = input_str("Basic Salary: ");
        (*X)->role = input_str("Role: ");
        sprintf((*X)->id, "%d", generate_rand_id(10000, 99999));
    }
}

int saveRecord(Employee *emp)
{
}

void listRecord(Employee *emp)
{
}

int modifyRecord(Employee *emp)
{
    return STATUS_SUCCESS;
}

int deleteRecord(Employee *emp)
{
    return STATUS_SUCCESS;
}