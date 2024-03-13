#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

// first run mkfifo /tmp/myfifo in shell

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo";

    mkfifo("/tmp/myfifo", 0666);

    // Open the FIFO for writing
    fd = open(myfifo, O_WRONLY);

    // Write a message to the FIFO
    write(fd, "Hello, World!\n", 14);

    // Close the FIFO
    close(fd);

    return 0;
}
