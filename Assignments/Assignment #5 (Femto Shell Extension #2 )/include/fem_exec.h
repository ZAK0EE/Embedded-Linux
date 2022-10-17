#ifndef FEM_EXEC_H
#define FEM_EXEC_H

#define EXEC_MAX_LOCAL 100
typedef struct
{
    char* name;
    int (*call)();
} command;


typedef struct
{
    char* left;
    char* right;
} assignment;

/**
* @brief This function is a wrapper that executes any command
*
* @param cmd    the name of the file/command
* @param argv[] the arguments array for the file/command
*
* @return       returns 1 on success and 0 on failure
*/
int fem_exec(char* cmd, char* argv[], char* envp[]);


/**
* @brief This function parses the given cmd as an assignment
*
* @param cmd the assignment string
*
* @return returns 1 on success and 0 on failure
*/
int fem_exec_assign(char* cmd);


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
int fem_exec_external(char* cmd, char* argv[], char* envp[]);

#endif /* FEM_EXEC_H */
