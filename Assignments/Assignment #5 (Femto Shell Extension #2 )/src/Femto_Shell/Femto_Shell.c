#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Femto_Shell.h"

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
    
    if((fgets(buff, sizeof(buff), stdin) == NULL))
        return 0;

    // The saveptr is used internally by strtok_r() in order to maintain context between successive calls that parse the same string.
    char* saveptr = NULL; 
    char* token = NULL;

    saveptr = buff;
    while((token = strtok_r(saveptr, " ", &saveptr)) != NULL)
    {
        femto_argv[femto_argc++] = token; // token is allocated memory inside strtok_r
    }

    for(int i = 0; femto_argv[i] != NULL; i++)
    {
        printf("argv[i]: %s\n", femto_argv[i]);
int Femto_Deconstruct()
{
    // Free allocated memory to the tokens
    while(femto_argc > 0)
    {
        femto_argc--;
        free(femto_argv[femto_argc]);
        femto_argv[femto_argc] = NULL;
    }

    return 1;
}

int Femto_Shell()
{
    while(1)
    {
        if(femto_argc == 0)
            Femto_ParseInput();
        // Femto_Localvar();
        // Femto_ExecBuiltin();
        // Femto_ExecExternal();
        //Femto_Deconstruct();
        Femto_Deconstruct();
    }

    return 1;        
}

