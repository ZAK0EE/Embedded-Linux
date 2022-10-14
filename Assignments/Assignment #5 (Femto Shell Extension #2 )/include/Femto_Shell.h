#ifndef FEMTO_SHELL_H
#define FEMTO_SHELL_H

#define FEMTO_MAX_ARGV 100

// Stores the input tokens as arugment variables
char* femto_argv[FEMTO_MAX_ARGV];

// Stores the number of tokens
int femto_argc;

// The current token index
int token_idx;

/**
* @brief This function starts the Femto Shell
*
* @return 1 on sucess
*/
int Femto_Shell();


/**
* @brief This function parses the input and stores tokens
*
* @return 1 on sucess
*/
int Femto_ParseInput();

#endif /* FEMTO_SHELL_H */
