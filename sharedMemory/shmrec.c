#include<stdio.h>
// shmget and shmat
#include<sys/shm.h>
#include<string.h>

int main(){
    int n;
    char *p;
    n=shmget(12321,25,IPC_CREAT|0666);
    if(n!=-1){
        p=(char *)shmat(n,NULL,0);
        printf("\n data = %s",p);
    }
    return 0;
}