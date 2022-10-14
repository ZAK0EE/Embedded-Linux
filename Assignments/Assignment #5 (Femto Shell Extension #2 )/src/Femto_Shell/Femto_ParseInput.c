#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Femto_ParseInput.h"


// Stores the input tokens as arugment variables
char* femto_argv[FEMTO_MAX_ARGV] = {NULL};


// Stores the number of tokens
int femto_argc = 0; 

// The current token index
int token_idx = 0;

int Femto_ParseInput()
{
    char buff[500] = {0};

    printf("Please enter your command > ");

    if((fgets(buff, sizeof(buff), stdin) == NULL) || buff[0]=='\n')
        return 0;

    // The saveptr is used internally by strtok_r() in order to maintain context between successive calls that parse the same string.
    char* saveptr = NULL; 
    char* token = NULL;
    char *alloc_token = NULL;

    // tokenizing the input
    saveptr = buff;
    while((token = strtok_r(saveptr, " \t\n", &saveptr)) != NULL)
    {
        alloc_token = strdup(token);
        femto_argv[femto_argc++] = alloc_token; // token is allocated memory inside strdup_
    }

//    // For debugging
//    for(int i = 0; femto_argv[i] != NULL; i++)
//    {
//        printf("argv[%d]: %s\n", i, femto_argv[i]);
//    }
//
    return 1;
}
