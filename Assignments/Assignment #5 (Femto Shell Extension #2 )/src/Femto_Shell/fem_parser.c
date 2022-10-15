#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fem_parser.h"


// Stores the input tokens as arugment variables
char* parser_argv[PARSER_MAX_ARGV] = {NULL};


// Stores the number of tokens
int parser_argc = 0; 

// The current token index
int token_idx = 0;

int fem_parser_input()
{
    char buff[500] = {0};

    printf("Please enter your command > ");

    char* ret;
    if(( (ret = fgets(buff, sizeof(buff), stdin)) == NULL) || buff[0]=='\n')
        return 0;
    
    // The saveptr is used internally by strtok_r() in order to maintain context between successive calls that parse the same string.
    char* saveptr = NULL; 
    char* token = NULL;
    char *alloc_token = NULL;

    // tokenizing the input
    saveptr = buff;
    while((token = strtok_r(saveptr, " ;\t\n", &saveptr)) != NULL)
    {
        alloc_token = strdup(token);
        parser_argv[parser_argc++] = alloc_token; // token is allocated memory inside strdup_
    }

    // No tokens parsed
    if(parser_argc == 0)
        return 0;

//    // For debugging
//    for(int i = 0; parser_argv[i] != NULL; i++)
//    {
//        printf("argv[%d]: %s\n", i, parser_argv[i]);
//    }
//
    return 1;
}
