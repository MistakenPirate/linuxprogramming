 
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
    } else {
        printf("Parent process: My PID is %d\n", getpid());
        printf("Parent process: Child's PID is %d\n", pid);
    }
    
    return 0;
}
