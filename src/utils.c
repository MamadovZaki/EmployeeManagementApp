#include "../include/utils.h"

int input_int(char *msg)
{
    /***********************************************************************************
     * Inputs: 
     **********
     * Message prompts user to input an integer value.
     
     * Description:
     *************** 
     * prompts a message to user
     * it takes string input from user and store it in a buffer 
     * stripes '\n' from the string 
     * dynamically allocate a new string and copies the value from buffer 
     * Note: Why using dynamic allocation? 
     *  We can't return buffer directly since it is a local variable 
     * 
     * When user inputs nothing but a newline (return key), the function returns 0
     *  !IT IS IMPORTAT TO FREE MEMORY AFTER USING THIS FUNCTION TO AVOID MEM LEAKS  
     * 
     * Output: 
     ***********
     * Returns the integer input from user 
     * Returns 0 if user didn't input any value 
     ***********************************************************************************/

    printf("%s", msg);

    char buf[10];
    int id;

    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0;

    // validates user input
    if (strcmp(buf, "") == 0)
        return 0;

    id = strtol(buf, NULL, 10);

    return id;
}