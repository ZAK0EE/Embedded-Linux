#include <stdlib.h>

#include "fem_shell.h"
#include "fem_parser.h"
#include "fem_exec.h"


int fem_deconstruct()
{
    // Free allocated memory to the tokens
    while(parser_argc > 0)
    {
        parser_argc--;
        free(parser_argv[parser_argc]);
        parser_argv[parser_argc] = NULL;
    }

    return 1;
}

int fem_shell()
{
    while(1)
    {
        if(!fem_parser_input())
            continue;
        // fem_Localvar();
        for(int i = parser_cmdidx; i < parser_cmdc; i++)
        {
		    fem_exec_builtin(*parser_cmdv[i]);
		    fem_exec_external(*parser_cmdv[i],  parser_cmdv[i]);        
        }
        
		parser_cmdidx = 0;
		parser_cmdc = 0;
        fem_deconstruct();
    }

    return 1;        
}

