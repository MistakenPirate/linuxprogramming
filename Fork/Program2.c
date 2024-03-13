#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: My parent's PID is %d\n", getppid());
    } else {
        printf("Parent process: My PID is %d\n", getpid());
    }
    
    return 0;
}
 
