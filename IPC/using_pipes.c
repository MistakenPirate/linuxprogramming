 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char message[] = "Hello, child!";

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipe_fd[1]); // Close write end
        char buffer[50];
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipe_fd[0]); // Close read end
    } else { // Parent process
        close(pipe_fd[0]); // Close read end
        write(pipe_fd[1], message, sizeof(message));
        close(pipe_fd[1]); // Close write end
    }

    return 0;
}
