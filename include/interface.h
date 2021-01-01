#pragma once

#define STATUS_SUCCESS 1
#define STATUS_FAILED 0
#define STATUS_UNDEFINED -1

typedef struct record
{
    int id;
    char *firstName;
    char *lastName;
    int age;
    float basic_salary;
    char *role;
} Record;

void DisplayProgramInterface();

int add_record();

int list_record();

int modify_record();

int delete_record();
