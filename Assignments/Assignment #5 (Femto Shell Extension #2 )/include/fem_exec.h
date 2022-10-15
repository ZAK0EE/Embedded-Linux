#ifndef FEM_EXEC_H
#define FEM_EXEC_H

typedef struct
{
    char* name;
    int (*call)();
} command;

/**
* @brief This function searches in builtin commands and execute if matches the input
*
* @param cmd name of the command that will be executed
*
* @return 
*/
int fem_exec_builtin(char* cmd);

/**
* @brief This function search for and executes external programs. It returns after the external program terminates
*
* @param cmd name of the command that will be executed
* @param argv[] pointer to the array of arguments that will be passed to the external program
*
* @return 
*/
int fem_exec_external(char* cmd, char* argv[]);

#endif /* FEM_EXEC_H */
