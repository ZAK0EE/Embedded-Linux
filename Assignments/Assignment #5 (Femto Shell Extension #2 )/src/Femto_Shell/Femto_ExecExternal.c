#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Femto_ParseInput.h"

int Femto_ExecExternal()
{
    execvpe(femto_argv[token_idx], &femto_argv[token_idx], NULL);
    printf("This msg won't be printed on sucess\n");

    return 1;
}
