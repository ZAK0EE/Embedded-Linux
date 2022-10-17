#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fem_parser.h"


// Stores the input tokens as arugment variables
char* parser_argv[PARSER_MAX_ARGV] = {NULL};


// Stores the number of tokens
int parser_argc = 0; 


// Stores a pointer to a command inside the parser_argv
char** parser_cmdv[PARSER_MAX_CMDV+1] = {NULL};

// Stores the number of commands stored in parser_cmdv
int parser_cmdc = 0;

// Stores the index of current cmd in parser_cmdv
int parser_cmdidx = 0;

/**
* @brief This function detects if ';' existed in the given range
*
* @param from the starting pointer of the range
* @param to the ending pointer of the range inclusively
*
* @return 
*/
int parser_commaExisted(char* from, char* to)
{
	for(char *i = from; i <= to; i++)
	{
		if(*i == ';')
		{
			return 1;
		}
	}
	
	return 0;
}


/**
* @brief This functions clears the input when input is bigger than the buffer
*/
void clear_stdin()
{
	int c;
	while ( (c = getchar()) != '\n' && c != EOF ) { }
}

int fem_parser_input()
{
	// original buffer, DONOT modify
    char org_buff[500] = {0};


    printf("Please enter your command > ");



    char* ret;
    if(( (ret = fgets(org_buff, sizeof(org_buff), stdin)) == NULL) || org_buff[0]=='\n')
        return 0;
    
    // CLear the stdin if input is bigger than the buffer
    size_t org_len = strlen(org_buff);
    if(org_buff[org_len -1] != '\n')
    {
    	printf("Input has been truncated!\n");
    	clear_stdin();
    }
    // The saveptr is used internally by strtok_r() in order to maintain context between successive calls that parse the same string.
    char* saveptr = NULL; 
    
    char* token = NULL;
    int tok_idx = -1; // token idx in the org_buff
    
    char *alloc_token = NULL;
	
	char* strtok_buff = strdup(org_buff);
	
	char* last_tok = NULL;
    // tokenizing the input
    saveptr = strtok_buff;
    while(parser_argc < PARSER_MAX_ARGV && parser_cmdc < PARSER_MAX_CMDV  &&
     (token = strtok_r(saveptr, " ;\t\n", &saveptr)) != NULL)
    {

    	
    	if(parser_cmdc == 0)
    	{
    		parser_cmdv[parser_cmdc++] = &parser_argv[parser_argc];
    	}
    	// Check if the delimiter is ';'
    	else 
    	{
    		// Detect the range of the delimiters between the two tokens
 		    tok_idx = (token - strtok_buff);
    		char* from = ((last_tok - strtok_buff) + strlen(last_tok)) + org_buff;
    		char* to = (tok_idx - 1) + org_buff;
    		
    		if(parser_commaExisted(from, to))
    		{
    			parser_argv[parser_argc++] = NULL;	
    			parser_cmdv[parser_cmdc++] = &parser_argv[parser_argc];    		
    		}

		}
		
		last_tok = token;
		
        alloc_token = strdup(token);
        parser_argv[parser_argc++] = alloc_token; // token is allocated memory inside strdup_
    }

    // No tokens parsed
    if(parser_argc == 0)
        return 0;

    return 1;
}

char **parser_getNextcmd()
{
	if(parser_cmdv[parser_cmdidx] == NULL)
		return NULL;
		
	return parser_cmdv[parser_cmdidx++];
}
