#include<stdio.h>
// shmget and shmat
#include<sys/shm.h>

int main(){
    int n;
    n=shmget(12321,25,IPC_CREAT|0666);
    if(n==-1){
        printf("\n test");
    }
    return 0;
}