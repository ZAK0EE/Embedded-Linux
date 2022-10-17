#include <stdlib.h>

#include "fem_shell.h"
#include "fem_parser.h"
#include "fem_exec.h"


int fem_deconstruct()
{
	if(!parser_deconstruct())
		return 0;
		
	return 1;
}


int fem_shell()
{
    while(1)
    {	
        if(!fem_parser_input())
            continue;

        char **cmd;
        while( (cmd = parser_getNextcmd()) != NULL)
        {
        	fem_exec(*cmd, cmd, environ);                  

        }
        	
        fem_deconstruct();
    }

    return 1;        
}

