#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    const char *ch = "/tmp/myfifo1234";
    int n,m;
    n=mkfifo(ch,0666);
    if(n==0){
	   m=open(ch,O_WRONLY);	
	   if(m!=1){
		   printf("\n enter the data");
		   scanf("%s",buf);

		   write(m,buf,strlen(buf)+1);
    }
    return 0;
