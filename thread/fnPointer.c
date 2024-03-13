#include<stdio.h>

void test(){
    printf("\n HELLO");
}

int main(){
    void (*ptr) ();
    ptr = &test;
    ptr();
    return 0;
}
