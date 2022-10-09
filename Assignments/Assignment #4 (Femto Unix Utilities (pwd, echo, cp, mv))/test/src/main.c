#include <stdio.h>
#include <unistd.h>

// Files includes
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Error includes
#include <string.h>
#include <errno.h>





int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("[ERROR] mv: missing file operand\n");
        printf("mv [src] [dst]\n");
        return -1;
    }

    int fd_src = open(argv[1], O_RDONLY);
    int fd_dst = open(argv[2], O_WRONLY | O_CREAT, S_IRWXU);



    char buf[500] = {0};
    ssize_t rbytes = 0;
    ssize_t wbytes = 0;

    while((rbytes = read(fd_src, buf, sizeof(buf))))
    {
        if(rbytes == -1)
        {
            printf("[ERROR] Error happened during read operation\n");
            return -1;
        }        

        wbytes = write(fd_dst, buf, rbytes);
        if(wbytes != rbytes || wbytes == -1)
        {
            printf("[ERROR] Error happened during write operation");
            return -1;
        } 
    }
    
    // delete the source file
    remove(argv[1]);
    
    close(fd_src);
    close(fd_dst);
    
    return 0;

}
