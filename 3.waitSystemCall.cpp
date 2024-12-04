#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main() {
	cout<<"Name: Ayush Budhlakoti"<<endl;
   	cout<<"Roll No: 2261123"<<endl;
    pid_t pid = fork();
    if (pid == 0) {
        cout<<"Child Process"<<endl;
        cout<<"Child Process Sleeping"<<endl;
        sleep(2);
        cout<<"Child Process Exited"<<endl;
        exit(0);
    } 
    else {
        cout<<"Parent Process"<<endl;
        wait(NULL);
        cout<<"Parent Process and Child Process Finished"<<endl;
    }
    return 0;
}