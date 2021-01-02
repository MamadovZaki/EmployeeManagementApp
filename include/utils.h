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
int input_int(char *);

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
char *input_str(char *);

/* generates a rand int */
int generate_rand_id(int, int);
