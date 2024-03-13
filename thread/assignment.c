#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 5;
pthread_mutex_t m;


void *test()
{
    if (x==5)
    {
    pthread_mutex_lock(&m);
    }
    x=x+10;
}

void *test1()
{
    x=x*10;
    pthread_mutex_unlock(&m);
}

int main()
{

    pthread_t id[2];
    pthread_mutex_lock(&m);
    pthread_create(&id[0], NULL, &test, 0);
    pthread_create(&id[1], NULL, &test1, 0);
    sleep(2);
    printf("\n x = %d",x);
    return 0;
}
