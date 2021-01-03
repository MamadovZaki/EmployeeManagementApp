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

extern char *_RECORDS;

void DisplayProgramInterface();

void generateRecord(Employee **);

int saveRecord(Employee *, const char *);

void listRecord(Employee *);

int modifyRecord(Employee *);

int deleteRecord(Employee *);
