#include "include/utils.h"
#include "include/interface.h"

int main(int argc, char const *argv[])
{
    Employee *employee;
    Employee *emp;
    int choice;
    int status;
    int id;
    char *_RECORDS = "/EmployeeRecords/records.txt";
    char cwd[200];
    char *out = getcwd(cwd, sizeof(cwd));
    if (out != NULL)
        strcat(cwd, _RECORDS);
    else
    {
        printf("Unable to find records.txt\n");
        exit(1);
    }

    while (1)
    {
        printf("\n----------------------\n");
        DisplayProgramInterface();
        printf("------------------------\n");

        choice = inpint("Enter Your choice: \n");

        switch (choice)
        {
        case 1:
            generateRecord(&employee);
            status = saveRecord(employee, cwd);

            if (status == STATUS_SUCCESS)
                printf("Record Saved.");
            else
                printf("Failed to save record, please try again later.\n");

            break;

        case 2:
            id = inpint("ID: ");
            if (id)
            {
                emp = findEmployee(cwd, id);
            }
            else
            {
                printf("Invalid ID.\n");
            }

            if (emp != NULL)
            {
                view_record(emp);

                free(emp);
            }
            else
                printf("Couldn't find an employee with this ID.\n");

            break;

        case 3:
            id = inpint("ID: ");
            if (id)
                emp = findEmployee(cwd, id);
            else
                printf("Invalid ID.\n");

            if (emp != NULL)
            {
                printf("Employee# %d: \n", id);
                view_record(emp);
                printf("\n\nPlease fill the form below with the updated info\n");
                printf("\nWARNING: If you don't want to amend the prompted piece of data, escape by pressing <Enter> \n");
                Employee *updated;
                generateRecord(&updated);
                status = modifyRecord(id, updated, cwd);
                if (status != STATUS_SUCCESS)
                    printf("An error occured. Please try again later.\n");
            }

            else
                printf("Couldn't find an employee with this ID.\n");

            break;

        case 4:
            id = inpint("ID: ");
            if (id)
                emp = findEmployee(cwd, id);
            else
                printf("Invalid ID.\n");

            if (emp != NULL)
            {
                printf("Employee# %d: \n", id);
                view_record(emp);

                printf("\nWARNING: Once data are deleted, it can't be retreived \n");
                char *answer = inpstr("Are you sure you want to proceed? [Y/N]\n");

                if ((strcmp(answer, "YES")) == 0 || (strcmp(answer, "yes")) == 0 || (strcmp(answer, "y")) == 0 || (strcmp(answer, "Y")) == 0)
                {
                    status = deleteRecord(id, emp, cwd);
                }
            }

            if (status == STATUS_SUCCESS)
            {
                printf("Record Deleted.");
            }
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nIncorrect choice, please choose properly .. \n");
            break;
        }
    }

    return 0;
}
