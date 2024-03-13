#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
    int fifo;
    char buffer[300];

    // Open FIFO for reading
    fifo = open(FIFO_FILE, O_RDONLY);
    if (fifo < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        // Receive message
        read(fifo, buffer, 300);
        if (strcmp(buffer, "exit") == 0) {
            printf("Termination message received. Exiting...\n");
            break;
        }
        printf("Received: %s\n", buffer);

        // Send response
        printf("Enter response: ");
        fgets(buffer, 300, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        fifo = open(FIFO_FILE, O_WRONLY);
        write(fifo, buffer, strlen(buffer) + 1);
        close(fifo);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Re-open FIFO for the next read
        fifo = open(FIFO_FILE, O_RDONLY);
    }

    close(fifo);
    return 0;
}

