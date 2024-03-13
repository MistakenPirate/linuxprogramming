#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t x;

//man pthread_create && pthread_mutex_lock

void *test()
{
    pthread_mutex_lock(&x);
    printf("\n HELLO");
}

void *test1()
{

    printf("\n WORLD");
    pthread_mutex_unlock(&x);
}

int main()
{

    pthread_t id[2];
    pthread_mutex_lock(&x);
    pthread_create(&id[0], NULL, &test, 0);
    pthread_create(&id[1], NULL, &test1, 0);
    sleep(2);
    return 0;
}
