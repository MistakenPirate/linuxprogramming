#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    int flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}


int main(){
    
    int arr[2],arr2[2],p,q,f;
    p = pipe(arr);
    q = pipe(arr2);
    f=fork();

    if(f==0){
        printf("\nchild\n");
        int buff2[20];
        read(arr[0],buff2,20);
        printf("\nstring = %d\n",buff2);
        bubbleSort(buff2,20);
        write(arr[1],buff2,20);

    }

    else{
        printf("\nparent\n");
        int buff[20]={1,7,0,123,4,6,1,5,7,8};
        // fgets(buff,sizeof(buff), stdin);
        write(arr[1],buff,20);

        read(arr[0],buff,20);
        printf("\nstring = %d\n",buff);


    }


    return 0;
}