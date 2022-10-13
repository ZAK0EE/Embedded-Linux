#include <stdio.h>

#include "Femto_Shell.h"


int Femto_Shell()
{
    while(1)
    {
        if(femto_argc == 0)
            Femto_ParseInput();
        // Femto_Localvar();
        // Femto_ExecBuiltin();
        // Femto_ExecExternal();
        //Femto_Deconstruct();
    }

    return 1;        
}

