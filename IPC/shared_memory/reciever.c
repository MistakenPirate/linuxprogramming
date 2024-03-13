#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shm_id;
    char *shm_addr;

    key = ftok("shared_mem", 'A');

    shm_id = shmget(key, SHM_SIZE,IPC_CREAT|0666);

    shm_addr = shmat(shm_id, NULL, 0);

    // printf("Enter message to write to shared memory: ");
    // fgets(shm_addr, SHM_SIZE, stdin);

    printf("Data written to shared memory: %s\n", shm_addr);

    shmdt(shm_addr);

    return 0;
}