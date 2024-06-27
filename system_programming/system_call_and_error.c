#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // close now uses this
#include <errno.h>

void main ()
{
    int fd;

    fd = open("foo", O_WRONLY | O_CREAT, 0644);

    // old tutorial don't know if write has been changed to fwrite.
    write(fd, "Hello World", 11);

    // using the errno which automatically set it gloablly and add it to the error table...
    if (fd < 0) {
      printf("error number is %d\n", errno);
      perror("foo");
      exit(1);
    }

    /**
     * if (( fd = open("foo", O_WRONLY | O_CREAT, 0644) ) < 0)
     * {
     *     // perfro error handling
     * }
     * 
    */

    // wasnt sure if close has been deprecated and now pclose
    close(fd);
}