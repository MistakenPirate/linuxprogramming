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

    key = ftok("msg_queue", 'B');
    msg_id = msgget(key, 0666 | IPC_CREAT);

    msg.msg_type = 1;
    printf("Enter message to send: ");
    fgets(msg.msg_text, MSG_SIZE, stdin);

    msgsnd(msg_id, &msg, sizeof(msg), 0);

    printf("Data sent is: %s\n", msg.msg_text);

    return 0;
}
