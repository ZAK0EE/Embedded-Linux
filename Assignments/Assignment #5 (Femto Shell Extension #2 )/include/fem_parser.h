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
* @return 1 on sucess
*/
int fem_parser_input();


#endif /* FEM_PARSER_H */