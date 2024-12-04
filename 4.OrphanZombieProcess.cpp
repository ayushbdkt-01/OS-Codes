#include <iostream>
#include <unistd.h>
#include <sys/wait.h> 
#include <cstdlib>  
using namespace std;
int main() {
    cout<<"Name: Ayush Budhlakoti"<<endl;
    cout<<"Roll. No: 2261123"<<endl;
    pid_t id = fork();
    if (id == 0) {
        cout<<"Zombie Child Process"<<endl;
        exit(0);
    } 
    else if (id > 0) {
        cout<<"Parent Process Created as child process"<<endl;
        sleep(5);
        wait(NULL);
    }

    id = fork();
    if (id == 0) {
        cout<<"Orphan Child Process"<<endl;
        cout<<"Child Process Sleeping"<<endl;
        sleep(3);
    } else if (id > 0) {
        cout<<"Parent Process"<<endl;
        cout<<"Parent PRocess exites"<<endl;
        exit(0);
    }
    return 0;
}