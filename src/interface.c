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
     * takes employee info and save it to a file
     
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
        (*X)->firstName = inpstr("First Name: ");
        (*X)->lastName = inpstr("Last Name: ");
        (*X)->age = inpstr("Age: ");
        (*X)->basic_salary = inpstr("Basic Salary: ");
        (*X)->role = inpstr("Role: ");
        sprintf((*X)->id, "%d", generate_rand_id(1000, 9999));
    }
}

int saveRecord(Employee *emp, const char *path)
{
    FILE *file;
    if (!feof(stdin))
        file = fopen(path, "a");

    if (file != NULL)
    {
        fprintf(file, "ID: %s\nName: %s %s\nAge: %s\nBasic Salary: %s\nRole: %s\n\n", emp->id, emp->firstName, emp->lastName, emp->age, emp->basic_salary, emp->role);
        fclose(file);
        return STATUS_SUCCESS;
    }

    return STATUS_FAILED;
}

Employee *findEmployee(const char *path, const int id)
{
    char buffer[25];
    char data[BUFFER_SIZE];
    long int *index;
    long int *line;
    sprintf(buffer, "%d", id);
    char *occurance;
    char name[100];
    char *fname;
    char *lname;
    char age[100];
    char salary[100];
    char role[100];
    Employee *emp = malloc(sizeof(Employee));
    FILE *file = fopen(path, "r");

    if (file != NULL)
    {
        if ((searchf(buffer, path, &line, &index)) != NULL)
        {
            fseek(file, *index, SEEK_SET);

            for (size_t i = 0; i < 4; i++)
            {
                fgets(data, sizeof(data), file);
                data[strcspn(data, "\n")] = 0;
                occurance = strstr(data, ":");
                occurance++; //skip semicolon
                occurance++; //skip whitespace

                switch (i)
                {
                case 0:
                    // reading line that contains: Name: xxx xxx
                    strcpy(name, occurance);
                    break;

                case 1:
                    strcpy(age, occurance);
                    break;

                case 2:
                    strcpy(salary, occurance);
                    break;

                case 3:
                    strcpy(role, occurance);
                    break;

                default:
                    break;
                }
            }
            printf("\nGathering employee's data .. \n");

            emp->firstName = malloc(200);
            emp->lastName = malloc(200);
            emp->age = malloc(200);
            emp->basic_salary = malloc(200);
            emp->role = malloc(200);

            fname = strtok(name, " ");
            strncpy(emp->firstName, fname, 200);

            lname = strtok(NULL, " ");
            strncpy(emp->lastName, lname, 200);

            strncpy(emp->age, age, 200);
            strncpy(emp->basic_salary, salary, 200);
            strncpy(emp->role, role, 200);
            fclose(file);

            return emp;
        }
        else
        {
            return NULL;
        }
    }
}

void view_record(Employee *emp)
{
    if (emp != NULL)
    {
        printf("First Name: %s\n", emp->firstName);
        printf("Last Name: %s\n", emp->lastName);
        printf("Age: %s\n", emp->age);
        printf("Basic Salary: %s\n", emp->basic_salary);
        printf("Role: %s\n", emp->role);
    }
}

int modifyRecord(int id, Employee *updatedEmp, const char *path)
{
    /***********************************************************************************
     * Inputs: 
     **********
     * employee's ID
     * Updated employee record 
     * Description:
     *************** 
     * If any field of the record is empty, then original data is preserved
     * If any field is not empty then it needs to be amended  
     * Output: 
     ***********
     * Returns 1 if successful operation 
     ***********************************************************************************/
    char buffer[BUFFER_SIZE];
    char buf_id[25];
    Employee *originalEmp;
    long int *index;
    long int *line;
    int status;

    //* Find the position in the file relative to zero where employee's ID is located */
    /* The position is the location of the newline that follows the id number in the file */
    sprintf(buf_id, "%d", id);
    searchf(buf_id, path, &line, &index);

    /* retreived original data to be able to concat original last name or first name*/
    originalEmp = findEmployee(path, id);

    /* Scan function input record */

    /* user wants to update the entire name */
    if (updatedEmp->firstName != NULL && updatedEmp->lastName != NULL)
    {
        strcpy(buffer, "Name: ");
        strcat(buffer, updatedEmp->firstName);
        strcat(buffer, " ");
        strcat(buffer, updatedEmp->lastName);
        strcat(buffer, "\n");
        status = updatef(path, *line + 1, buffer);
        if (status == STATUS_SUCCESS)
        {
            printf("Updated Employee's Name Successfully ..\n");
        }
        else
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
    }
    /* user wants to update first name only */
    if (updatedEmp->firstName != NULL && updatedEmp->lastName == NULL)
    {
        strcpy(buffer, "Name: ");
        strcat(buffer, updatedEmp->firstName);
        strcat(buffer, " ");
        strcat(buffer, originalEmp->lastName);
        strcat(buffer, "\n");
        status = updatef(path, *line + 1, buffer);
        if (status == STATUS_SUCCESS)
        {
            printf("Updated Employee's First Name Successfully ..\n");
        }
        else
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
    }
    /* user wants to update last name only */
    if (updatedEmp->firstName == NULL && updatedEmp->lastName != NULL)
    {
        strcpy(buffer, "Name: ");
        strcat(buffer, originalEmp->firstName);
        strcat(buffer, " ");
        strcat(buffer, updatedEmp->lastName);
        strcat(buffer, "\n");
        status = updatef(path, *line + 1, buffer);
        if (status == STATUS_SUCCESS)
        {
            printf("Updated Employee's First Name Successfully ..\n");
        }
        else
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
    }

    if (updatedEmp->age != NULL)
    {
        strcpy(buffer, "Age: ");
        strcat(buffer, updatedEmp->age);
        strcat(buffer, "\n");
        status = updatef(path, *line + 2, buffer);
        if (status != STATUS_SUCCESS)
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
        else
        {
            printf("Updated Employee's Age Successfully ..\n");
        }
    }

    if (updatedEmp->basic_salary != NULL)
    {
        strcpy(buffer, "Basic Salary: ");
        strcat(buffer, updatedEmp->basic_salary);
        strcat(buffer, "\n");
        status = updatef(path, *line + 3, buffer);
        if (status != STATUS_SUCCESS)
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
        else
        {
            printf("Updated Employee's Basic Salary Successfully ..\n");
        }
    }

    if (updatedEmp->role != NULL)
    {
        strcpy(buffer, "Role: ");
        strcat(buffer, updatedEmp->role);
        strcat(buffer, "\n");
        status = updatef(path, *line + 4, buffer);
        if (status != STATUS_SUCCESS)
        {
            printf("Failed to update due to internal error .. \n");
            return STATUS_FAILED;
        }
        else
        {
            printf("Updated Employee's Role Successfully ..\n");
        }
    }

    return STATUS_SUCCESS;
}

int deleteRecord(int id, Employee *emp, const char *path)
{
    int status;
    long int *line;
    long int *index;
    char buf[25];
    sprintf(buf, "%d", id);
    char *check = searchf(buf, path, &line, &index);

    if (check != NULL)
    {
        for (int i = 0; i < 6; i++)
        {
            status = updatef(path, *line, "");
            if (status != STATUS_SUCCESS)
            {
                printf("Failed to delete line#%d.. \n", i);
                return STATUS_FAILED;
            }
        }
    }

    return STATUS_FAILED;
}