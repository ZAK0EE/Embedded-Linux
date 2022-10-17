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


command builtin_commands[] =
{
    {"rand" ,femto_rand},
    {"fib", femto_fib},
    {"fact", femto_fact},
    {"set", femto_set},
    {"export", femto_export},
    {NULL, NULL}
};

// A set of local assignments
assignment exec_local[EXEC_MAX_LOCAL] = {NULL};

// Stores the number of assignments stored in exec_local
int exec_localc = 0;


int femto_set(char* argv[])
{
	for(int i = 0; i < exec_localc; i++)
	{
		printf("local_var[%d]: %s = %s\n", i, exec_local[i].left, exec_local[i].right);
	}
	
	return 1;
}


int femto_export(char* argv[])
{
	if(argv[1] == NULL)
	{
		printf("SYNTAX: export VAR\n");
		return 1;
	}
	
	for(int i = 0; i < exec_localc; i++)
	{
		if(strcmp(argv[1], exec_local[i].left) == 0)
		{
			setenv(exec_local[i].left, exec_local[i].right, 1);
			return 1;
		}
	}
	
	printf("Could not export [%s]: variable not found\n", argv[1]); 
	
	return 1;
}


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

	exec_local[exec_localc].left = strndup(cmd, assign_idx);
	exec_local[exec_localc].right = strdup(&cmd[assign_idx + 1]);
	
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
