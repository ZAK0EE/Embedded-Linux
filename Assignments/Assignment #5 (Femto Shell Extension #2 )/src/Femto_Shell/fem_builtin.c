#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fem_builtin.h"

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


int femto_exit(char* argv[])
{
	exit(0);
}


int femto_help(char* argv[])
{
	printf(
	"***Built-in commands***\n"
	"rand: prints a random number\n"
	"fib: prints Fibonacci sequence\n"
	"fact: prints factorial number\n"
	"set: prints local variables\n"
	"export: exports the variable to environment\n"
	"help: shows a brief about built-in commands\n"
	"exit: exits the shell\n"
	);
	
	return 1;
}
//****************************************************************************************************************

