#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: My parent's PID is %d\n", getppid());
    } else {
        wait(NULL); // Wait for the child to finish
        printf("Parent process: My PID is %d\n", getpid());
    }
    
    return 0;
}
 
