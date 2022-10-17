#ifndef FEM_SHELL_H
#define FEM_SHELL_H

// A pointer to an array of user environment, passed externally by the parent process
extern char **environ;

/**
* @brief This function starts the Femto Shell
*
* @return 1 on sucess and 0 on failure
*/
int fem_shell();


/**
* @brief This function parses the input and stores tokens
*
* @return 1 on sucess and 0 on failure
*/
int fem_parser();

#endif /* FEM_SHELL_H */
