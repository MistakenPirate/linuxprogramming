#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 128

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[BUF_SIZE];

    // Open the FIFO for reading
    fd = open(myfifo, O_RDONLY);

    // Read from the FIFO
    read(fd, buf, BUF_SIZE);

    // Print the received message
    printf("Received: %s", buf);

    // Close the FIFO
    close(fd);

    unlink("/tmp/myfifo");

    return 0;
}

