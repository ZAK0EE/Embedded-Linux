#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fem_exec.h"


#include "libinclude/femto_rand.h"
#include "libinclude/femto_fib.h"
#include "libinclude/femto_fact.h"

#include "fem_builtin.h"

command builtin_commands[] =
{
    {"rand" ,femto_rand},
    {"fib", femto_fib},
    {"fact", femto_fact},
    {"set", femto_set},
    {"export", femto_export},
    {"help", femto_help},
    {"exit", femto_exit},
    {NULL, NULL}
};

// A set of local assignments
assignment exec_local[EXEC_MAX_LOCAL] = {NULL};

// Stores the number of assignments stored in exec_local
int exec_localc = 0;



int fem_exec(char* cmd, char* argv[], char* envp[])
{
	if(fem_exec_assign(cmd))
	{
		return 1;
	}
	else if(fem_exec_builtin(cmd, argv))
	{
		return 1;
	}
	else if(fem_exec_external(cmd, argv, envp))
	{
		return 1;
	}
	else
	{
		printf("%s: command was not found\n", cmd);
	}
	
	return 0;
}


int fem_exec_assign(char* cmd)
{
	if(exec_localc == EXEC_MAX_LOCAL || (!isalpha(cmd[0]) && cmd[0] != '_'))
		return 0;
	
	// Assignment index
	char* ret = strchr(cmd, '=');
	if(ret == NULL)
		return 0;
		
	int assign_idx = ret - cmd;
	
	char* left = strndup(cmd, assign_idx);
	char* right = strdup(&cmd[assign_idx + 1]);
	
	// Check if variable exists
	for(int i = 0; i < exec_localc; i++)
	{
		if(strcmp(left, exec_local[i].left) == 0)
		{
			free(left);
			free(exec_local[i].right);
			
			exec_local[i].right = right;
			return 1;
		}
	}
	
	exec_local[exec_localc].left = left;
	exec_local[exec_localc].right = right;
	
	exec_localc++;
	
	return 1;
}


int fem_exec_builtin(char* cmd, char* argv[])
{

    for(int i = 0; builtin_commands[i].name != NULL; i++)
    {
        if(strcmp(cmd, builtin_commands[i].name) == 0)
        {
            return builtin_commands[i].call(argv);
        }
    }
    
    return 0;
}


int fem_exec_external(char* cmd, char* argv[], char* envp[])
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
       execvpe(cmd, argv, envp);
       exit(-1); // In case, exec failed
    }
    
    return 1;
}
