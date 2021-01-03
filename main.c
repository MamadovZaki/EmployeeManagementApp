#include "include/utils.h"
#include "include/interface.h"

int main(int argc, char const *argv[])
{
    Employee *employee;
    int choice;
    int status;
    char *_RECORDS = "/EmployeeRecords/records.txt";
    char cwd[200];
    char *out = getcwd(cwd, sizeof(cwd));
    if (out != NULL)
        strcat(cwd, _RECORDS);
    else
        printf("Unable to find records.txt\n");

    while (1)
    {
        printf("\n----------------------\n");
        DisplayProgramInterface();
        printf("------------------------\n");

        choice = input_int("Enter Your choice: \n");

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

            if (STATUS_SUCCESS)
                printf("Record Found.");

            break;

        case 3:

            if (STATUS_SUCCESS)
            {
                printf("Record Modified.");
            }
            break;

        case 4:

            if (STATUS_SUCCESS)
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
