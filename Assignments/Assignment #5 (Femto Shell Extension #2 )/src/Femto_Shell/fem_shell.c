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
        fem_exec_builtin(parser_argv[token_idx]);
        fem_exec_external(parser_argv[token_idx], &parser_argv[token_idx]);
        fem_deconstruct();
    }

    return 1;        
}

