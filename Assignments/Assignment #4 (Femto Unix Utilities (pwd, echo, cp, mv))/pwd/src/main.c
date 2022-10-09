#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    char buf[500] = {0};
 
    char *result;
    result = getcwd(buf, sizeof(buf));

    if(result != NULL)
    {
        printf("%s\n", buf);
    }
    else
    {
    
        printf("Error: %s\n", strerror(errno));
    }

}
