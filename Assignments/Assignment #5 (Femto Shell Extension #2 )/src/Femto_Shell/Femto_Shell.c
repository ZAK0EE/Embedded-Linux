#include <stdlib.h>

#include "Femto_Shell.h"
#include "Femto_ParseInput.h"
#include "Femto_ExecBuiltin.h"
#include "Femto_ExecExternal.h"


int Femto_Deconstruct()
{
    // Free allocated memory to the tokens
    while(femto_argc > 0)
    {
        femto_argc--;
        free(femto_argv[femto_argc]);
        femto_argv[femto_argc] = NULL;
    }

    return 1;
}

int Femto_Shell()
{
    while(1)
    {
        if(!Femto_ParseInput())
            continue;
        // Femto_Localvar();
        Femto_ExecBuiltin();
        Femto_ExecExternal();
        Femto_Deconstruct();
    }

    return 1;        
}

