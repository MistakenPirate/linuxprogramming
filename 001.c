#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int ar[2],j;
    j=fork();

    if(j==0){
        printf("child\n");
    }

    else{
        printf("parent\n");
    }
}