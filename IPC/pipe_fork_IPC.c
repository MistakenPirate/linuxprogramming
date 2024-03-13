// Uisng pipe and fork function send this array from parent to child process. In child process, sort this array, then send back the sorted array to parent process and print the array

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int pipeFD1[2]; // Parent to child
    int pipeFD2[2]; // Child to parent
    pid_t pid;
    int arr[] = {40, 70, 4, 90, 20, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create pipes
    if (pipe(pipeFD1) == -1 || pipe(pipeFD2) == -1) {
        perror("pipe failed");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid > 0) {  // Parent process
        close(pipeFD1[0]); // Close reading end of first pipe
        close(pipeFD2[1]); // Close writing end of second pipe

        // Write array to pipe
        write(pipeFD1[1], arr, sizeof(arr));

        //-----------------------------------------------------------------//

        // Wait for the sorted array from the child
        read(pipeFD2[0], arr, sizeof(arr));

        // Print the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else {  // Child process
        close(pipeFD1[1]); // Close writing end of first pipe
        close(pipeFD2[0]); // Close reading end of second pipe

        // Read array from pipe
        read(pipeFD1[0], arr, sizeof(arr));

        // Sort the array
        bubbleSort(arr, n);

        // Send sorted array back to parent
        write(pipeFD2[1], arr, sizeof(arr));
    }

    return 0;
}

