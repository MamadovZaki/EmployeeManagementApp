#include "include/utils.h"
#include "include/interface.h"

int main(int argc, char const *argv[])
{
    int choice;
    int status;
    char *struct_info = {
        "Employee",
        "id",
        "firstName",
        "lastName",
        "age",
        "basic_salary",
        "role"};

    while (1)
    {
        printf("\n----------------------\n");
        DisplayProgramInterface();
        printf("------------------------\n");

        choice = input_int("Enter Your choice: \n");

        switch (choice)
        {
        case 1:
            Employee *employee = NULL;
            generateRecord(&employee);
            status = saveRecord(employee);

            if (STATUS_SUCCESS)
            {
                printf("Record Saved.");
            }

            break;

        case 2:

            if (STATUS_SUCCESS)
            {
                printf("Record Found.");
            }
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
