#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


int fem_exec(char* cmd, char* argv[])
{
	if(fem_exec_builtin(cmd))
	{
		return 1;
	}
	else if(fem_exec_external(cmd, argv))
	{
		return 1;
	}
	else
	{
		printf("%s: command was not found\n", cmd);
	}
	
	return 0;
}

int fem_exec_builtin(char* cmd)
{

    for(int i = 0; builtin_commands[i].name != NULL; i++)
    {
        if(strcmp(cmd, builtin_commands[i].name) == 0)
        {
            return builtin_commands[i].call();
        }
    }
    
    return 0;
}

int fem_exec_external(char* cmd, char* argv[])
{
    int status = 0;
    int ret_pid = fork();

    if(ret_pid < 0)
    {
    	printf("Failed to execute\n");
    }
    else if(ret_pid > 0)
    {
        wait(&status);
        // Failed to execute
        if(WEXITSTATUS(status) == (unsigned char)-1)
        	return 0;
    }
    else if(ret_pid == 0)
    {
       execvpe(cmd, argv, NULL);
       exit(-1); // In case, exec failed
    }
    
    return 1;
}
