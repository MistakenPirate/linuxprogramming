#include<stdio.h>
// shmget and shmat
#include<sys/shm.h>
#include<string.h>

int main(){
    int n;
    char *p,buf[20];
    n=shmget(12321,25,IPC_CREAT|0666);
    if(n!=-1){
        p=(char *)shmat(n,NULL,0);
        printf("\n enter the data");
        scanf("%[^\n]s",buf);
        strcpy(p,buf);
    }
    return 0;
}