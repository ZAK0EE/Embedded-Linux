#include <stdio.h>
#include <string.h>
#include "Femto_ExecBuiltin.h"
#include "Femto_ParseInput.h"

#include "libinclude/femto_rand.h"
#include "libinclude/femto_fib.h"
#include "libinclude/femto_fact.h"

command builtin_commands[] =
{
    {"rand" ,femto_rand},
    {"fib", femto_fib},
    {"fact", femto_fact},
    {NULL, NULL}
};


int Femto_ExecBuiltin()
{

    for(int i = 0; builtin_commands[i].name != NULL; i++)
    {
        if(strcmp(femto_argv[token_idx], builtin_commands[i].name) == 0)
        {
            builtin_commands[i].call();
            break;
        }
    }
    
    return 1;
}

