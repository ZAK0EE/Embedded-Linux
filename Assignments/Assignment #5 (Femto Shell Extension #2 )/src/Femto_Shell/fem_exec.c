#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fem_exec.h"


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


int fem_exec_builtin(char* cmd)
{

    for(int i = 0; builtin_commands[i].name != NULL; i++)
    {
        if(strcmp(cmd, builtin_commands[i].name) == 0)
        {
            builtin_commands[i].call();
            break;
        }
    }
    
    return 1;
}

int fem_exec_external(char* cmd, char* argv[])
{
    int status = 0;
    int ret_pid = fork();

    if(ret_pid < 0)
    {
        printf("This msg won't be printed on sucess\n");
    }
    else if(ret_pid > 0)
    {
        wait(&status);
    }
    else if(ret_pid == 0)
    {
        execvpe(cmd, argv, NULL);
    }


    return 1;
}
