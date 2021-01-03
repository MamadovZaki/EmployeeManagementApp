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

int modifyRecord(Employee *emp)
{
    return STATUS_SUCCESS;
}

int deleteRecord(Employee *emp)
{
    return STATUS_SUCCESS;
}
