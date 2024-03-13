#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        sleep(3); // Simulate some work
    } else {
        printf("Parent process: My PID is %d\n", getpid());
        printf("Parent process: Waiting for child to finish...\n");
        wait(&status); // Wait for child process to finish
        printf("Parent process: Child process finished\n");
    }
    
    return 0;
}
 
