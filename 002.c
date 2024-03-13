#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    
    int arr[2],p,f;
    p = pipe(arr);
    f=fork();

    if(f==0){
        printf("\nchild\n");
        char buff2[10];
        read(arr[0],buff2,10);
        printf("\nstring = %s\n",buff2);
    }

    else{
        printf("\nparent\n");
        char buff[10]="hello";
        write(arr[1],buff,6);
    }


    return 0;
}