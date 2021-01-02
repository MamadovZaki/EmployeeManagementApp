#include "../include/utils.h"

int input_int(char *msg)
{
    printf("%s", msg);

    char buf[100];
    int id;

    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0; // remove newline character

    // validates user input
    if (strcmp(buf, "") == 0)
        return 0;

    id = strtol(buf, NULL, 10);

    return id;
}

char *input_str(char *msg)
{
    char *str;
    char buffer[100];
    int buffer_size = sizeof(buffer);

    printf("%s", msg);

    /* accepts string input from user */
    fgets(buffer, buffer_size, stdin);
    /* remove "\n" from the string */
    buffer[strcspn(buffer, "\n")] = 0;

    /* check if user has entered an empty string */
    if ((strcmp(buffer, "")) == 0)
        return NULL;

    /* allocate memory space for the new string, sized to the content of the buffer*/
    /* Extra byte added to allocate \0 */
    str = malloc(strlen(buffer) + 1);
    /* copy the trimmed content up to \0 to the new string */
    strcpy(str, buffer);

    return str;
}

int generate_rand_id(int MAX, int MIN)
{
    srand(time(NULL));
    int randomID = rand() % MAX + MIN;
    return randomID;
}
