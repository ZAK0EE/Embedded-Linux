#ifndef FEM_PARSER_H
#define FEM_PARSER_H

#define PARSER_MAX_ARGV 100

// Stores the input tokens as arugment variables
char* parser_argv[PARSER_MAX_ARGV];


// Stores the number of tokens
int parser_argc;

// The current token index
int token_idx;

/**
* @brief This function parses the input and stores tokens
*
* @return 1 on sucess
*/
int fem_parser_input();


#endif /* FEM_PARSER_H */
