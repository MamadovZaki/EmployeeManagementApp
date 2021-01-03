#pragma once

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFFER_SIZE 1000
extern int errno;

/*******************************************************
     * Inputs: 
     **********
     * Message prompts user to input an integer value.
     
     * Description:
     *************** 
     * prompts a message to user to enter an integer value.
     
     * Output: 
     ***********
     * Returns the integer input from user. 
     * Returns 0 if user didn't input a valid value.
     *******************************************************/
int inpint(char *);

/*******************************************************
     * Inputs: 
     **********
     * Message prompts user to input a string value.
     
     * Description:
     *************** 
     * prompts a message to user to enter a string and returns a pointer to this string.
     
     * Output: 
     ***********
     * Returns the string inputted by user. 
     * Returns NULL if memo allocation failed.
     *******************************************************/
char *inpstr(char *);

/* generates a rand int */
int generate_rand_id(int, int);

/*******************************************************
     * Inputs: 
     **********
     * const char* path: path to a file
     
     * Description:
     *************** 
     * stores the size of a file in bytes in a pointer 
     
     * Output: 
     ***********
     * Returns a non-0 value if file is found. 
     * Returns 0 if file is not found.
     *******************************************************/
long int fsize(const char *);

/*******************************************************
     * Inputs: 
     **********
     * const char* key: data to look for in a file
     * const char* path: path to the file in question 
     * int* line : line# where key resides
     * int* index: index# where key resides  
     
     * Description:
     *************** 
     * search file for key value and store index and line# in int* line, int* index when found, otherwise, function returns NULL. 
     
     * Output: 
     ***********
     * Returns a non-NULL value if key is found. 
     * Returns NULL if key is not found.
     *******************************************************/
char *searchf(const char *, const char *, long int **, long int **);