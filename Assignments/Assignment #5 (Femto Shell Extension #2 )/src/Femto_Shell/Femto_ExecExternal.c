#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Femto_ParseInput.h"

int Femto_ExecExternal()
{
    int status = 0;
    int ret_pid = fork();

    if(ret_pid < 0)
    {
        printf("This msg won't be printed on sucess\n");
    }
    else if(ret_pid > 0)
    {
        wait(&status);
    }
    else if(ret_pid == 0)
    {
        execvpe(femto_argv[token_idx], &femto_argv[token_idx], NULL);
    }


    return 1;
}
