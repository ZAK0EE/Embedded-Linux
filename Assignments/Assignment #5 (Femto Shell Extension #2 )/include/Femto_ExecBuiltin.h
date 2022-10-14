#ifndef FEMTO_EXECBUILTIN_H
#define FEMTO_EXECBUILTIN_H

typedef struct
{
    char* name;
    int (*call)();
} command;
/**
* @brief This function searches in builtin commands and execute if matches the input
*
* @return 1 on sucess and 0 on failure 
*/
int Femto_ExecBuiltin();

#endif /* FEMTO_EXECBUILTIN_H */
