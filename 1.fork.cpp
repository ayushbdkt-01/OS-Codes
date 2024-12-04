#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main(){
    cout<<"Name: Ayush Budhlakoti"<<endl;
    cout<<"Roll No: 2261123"<<endl;
    pid_t id=fork();
    if(id<0){
        cout<<"Fork Falied"<<endl;
        return 0;
    }
    else if(id==0) cout<<"Child Process"<<endl;
    else cout<<"Parent Process"<<endl;
    return 0;
}