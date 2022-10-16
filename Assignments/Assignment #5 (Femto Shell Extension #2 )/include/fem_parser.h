#ifndef FEM_PARSER_H
#define FEM_PARSER_H

#define PARSER_MAX_ARGV 100
#define PARSER_MAX_CMDV 20

// Stores the input tokens as arugment variables
char* parser_argv[PARSER_MAX_ARGV];

// Stores the number of tokens
int parser_argc;

// Stores a pointer to a command inside the parser_argv
char** parser_cmdv[PARSER_MAX_CMDV+1];

// Stores the number of commands stored in parser_cmdv
int parser_cmdc;

// Stores the index of current cmd in parser_cmdv
int parser_cmdidx;


/**
* @brief This function parses the input and stores tokens
*
* @return 1 on sucess and 0 on failure
*/
int fem_parser_input();


/**
* @brief This function returns a pointer to a command name
*
* @return pointer to a pointer to command name on sucess and NULL on failure
*
* @Note You can -and should- use this pointer to pointer as a pointer to an array of arguments like argv[]
* As the command name is followed by its arguments in a null-termianted string
*/
char **parser_getNextcmd();


#endif /* FEM_PARSER_H */
