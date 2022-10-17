#ifndef FEM_BUILTIN_H
#define FEM_BUILTIN_H


#include "fem_exec.h"

/**
* @brief this function prints all local variables
*
* @param argv[] pointer to the array of arguments that will be passed to the builtin program
*
* @return returns 1 on success and 0 on failure
*/
int femto_set(char* argv[]);


/**
* @brief this function exports the given variable to the environment variables
*
* @param argv[] pointer to the array of arguments that will be passed to the builtin program
*
* @return returns 1 on success and 0 on failure
*/
int femto_export(char* argv[]);


/**
* @brief this function exits the shell
*
* @param argv[] pointer to the array of arguments that will be passed to the builtin program
*
* @return returns 1 on success and 0 on failure
*/
int femto_exit(char* argv[]);


/**
* @brief this function prints help messages for local functions
*
* @param argv[] pointer to the array of arguments that will be passed to the builtin program
*
* @return returns 1 on success and 0 on failure
*/
int femto_help(char* argv[]);

#endif /* FEM_BUILTIN_H */
