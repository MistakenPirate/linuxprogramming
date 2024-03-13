#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 3

//Structure to represent a task
typedef struct{
	int data;
} Task;

// Shared buffer with semaphore-like logic
Task buffer[BUFFER_SIZE];
int head = 0;
int tail = 0;
int count = 0; //keeps track of items in the buffer
	       
// Semaphore-like function (simulated with busy waiting)
void wait_empty(){
	while(count == BUFFER_SIZE){
		//Busy waiting - wait if buffer is full
	}
}

void wait_full(){
	while(count==0){
		//Busy waiting - wait if buffer is empty
	}
}

void signal_empty(){
	count++;
}

void signal_full(){
	count--;
}

//Producer Function

void producer(int data){
	wait_empty();
	buffer[tail].data = data;
	tail = (tail+1)%BUFFER_SIZE;
	printf("Producer added: %d\n",data);
	signal_full();
}

//Consumer Function
void consumer(){
	wait_full();
	int data=buffer[head].data;
	head=(head+1)%BUFFER_SIZE;
	printf("Consumer removed: %d\n",data);
	signal_empty();
}

int main(){
	//Simulate producer and consumer processes
	producer(1);
	producer(2);
	producer(3);
	producer(4);

	consumer();
	consumer();

	producer(5);

	consumer();
	consumer();
	return 0;
}
