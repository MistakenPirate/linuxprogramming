#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 128

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key;
    int msg_id;
    struct message msg;

    key = ftok("msg_queue", 'C');
    msg_id = msgget(key, 0666 | IPC_CREAT);

    // Receive the first available message of any type
    msgrcv(msg_id, &msg, sizeof(msg) - sizeof(long), 0, 0);

    printf("Received message: %s\n", msg.msg_text);

    return 0;
}
