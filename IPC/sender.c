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

    // Open FIFO for writing
    fifo = open(FIFO_FILE, O_WRONLY);
    if (fifo < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        // Get user input
        printf("Enter message: ");
        fgets(buffer, 300, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Send message
        write(fifo, buffer, strlen(buffer) + 1);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Wait for response
        fifo = open(FIFO_FILE, O_RDONLY);
        read(fifo, buffer, 300);
        printf("Received: %s\n", buffer);
        close(fifo);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Re-open FIFO for the next write
        fifo = open(FIFO_FILE, O_WRONLY);
    }

    close(fifo);
    return 0;
}

