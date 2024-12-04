#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;
int main() {
    int fd[2];
    char writeMessage[] = "Hello from Parent!";
    char readMessage[100];
    pid_t id = fork();
    if (id > 0) {
        close(fd[0]);
        write(fd[1], writeMessage, strlen(writeMessage) + 1);
        close(fd[1]);
        cout<<"Paremt Sends message to child"<<endl;
    } 
    else {
        close(fd[1]);
        read(fd[0], readMessage, sizeof(readMessage));
        cout<<"Child Received the Message"<<endl;
        close(fd[0]);
    }
    return 0;
}