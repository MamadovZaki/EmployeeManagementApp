#include "include/utils.h"
#include "include/interface.h"

int main(int argc, char const *argv[])
{
    Record employee;
    int choice;
    int status;

    while (1)
    {
        printf("\n----------------------\n");
        DisplayProgramInterface();
        printf("------------------------\n");

        choice = input_int("Enter Your choice: \n");

        switch (choice)
        {
        case 1:
            status = add_record();

            if (STATUS_SUCCESS)
            {
                printf("Record Added.");
            }

            break;

        case 2:
            status = list_record();

            if (STATUS_SUCCESS)
            {
                printf("Record Found.");
            }
            break;

        case 3:
            status = modify_record();

            if (STATUS_SUCCESS)
            {
                printf("Record Modified.");
            }
            break;

        case 4:
            status = delete_record();

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
