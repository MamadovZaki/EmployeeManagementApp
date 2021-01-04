#include "../include/utils.h"

int inpint(char *msg)
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

char *inpstr(char *msg)
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

long int fsize(const char *path)
{
    int size;
    FILE *file;
    file = fopen(path, "r");
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END); /* SET the position at EOF */
        size = ftell(file);       /* Record the pos at EOF to return size of file in bytes */
        rewind(file);             /* Return to Origin - position 0 */
        fclose(file);

        return size;
    }

    return 0;
}

char *searchf(const char *key, const char *path, long int **LINE, long int **INDEX)
{
    long int flen = fsize(path); // stores file size
    long int klen = strlen(key); // stores key size
    char buffer[BUFFER_SIZE];
    *LINE = malloc(sizeof(long int));
    **LINE = 1;
    *INDEX = malloc(sizeof(long int));
    **INDEX = 0;

    FILE *file = fopen(path, "r");
    char *check;
    char *psh;

    if (file != NULL)
    {
        while (**LINE < flen)
        {
            check = fgets(buffer, sizeof(buffer), file);
            if (check != NULL)
            {
                psh = strstr(buffer, key);
                if (psh != NULL)
                {
                    **INDEX = ftell(file);
                    printf("Found a match .. \n");
                    printf("Scanned %ld lines\nScanned %ld Bytes\n", **LINE, **INDEX);
                    fclose(file);
                    return psh;
                }
                **LINE += 1; // !DON'T USE **LINE++ AS IT PRODUCES GARBAGE VALUE
            }
            else
            {
                break;
            }
        }

        printf("Search parameter is not found.\n");
        printf("Reached end of file.\n");
        fclose(file);
        return NULL;
    }

    printf("Records.txt is not found.\n");
    return NULL;
}

int updatef(const char *path, int line, const char *newline)
{
    FILE *file;
    FILE *fileTemp;
    char buffer[BUFFER_SIZE];
    int count = 0;

    /*  Open all required files */
    file = fopen(path, "r");

    // construct a new path
    char *_temp = "/EmployeeRecords/freplace.txt";
    char _cwd[200];
    char *out = getcwd(_cwd, sizeof(_cwd));
    if (out != NULL)
        strcat(_cwd, _temp);
    else
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        return 0;
    }

    fileTemp = fopen(_cwd, "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (file == NULL || fileTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        return 0;
    }

    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */

    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fileTemp);
        else
            fputs(buffer, fileTemp);
    }

    /* Close all files to release resource */
    fclose(file);
    fclose(fileTemp);

    /* Delete original source file */
    if ((remove(path)) != 0)
    {
        printf("Error, terminating.\n");
        exit(1);
    }

    /* Rename temporary file as original file */
    if ((rename(_cwd, path)) != 0)
    {
        printf("Error, terminating.\n");
        exit(1);
    }

    /* Strip the newline for a better looking log message :) */
    if (strcmp(newline, "") != 0)
    {
        //newline[strcspn(newline, "\n")] = 0;
        printf("\nSuccessfully updated file..\n");
    }
    else
    {
        printf("\nSuccessfully deleted line#%d ..\n", line);
    }

    return 1;
}
