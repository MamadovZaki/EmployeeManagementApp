#pragma once

#define STATUS_SUCCESS 1
#define STATUS_FAILED 0
#define STATUS_UNDEFINED -1

typedef struct record
{
    char id[30];
    char *firstName;
    char *lastName;
    char *age;
    char *basic_salary;
    char *role;
} Employee;

void DisplayProgramInterface();

void generateRecord(Employee **);

int saveRecord(Employee *);

void listRecord(Employee *);

int modifyRecord(Employee *);

int deleteRecord(Employee *);
