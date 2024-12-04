#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main(){
    cout<<"Name: Ayush Budhlakoti"<<endl;
    cout<<"Roll No: 2261123"<<endl;
    pid_t id=fork();
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    if(id==0){
        int sum=0;
        for(int i=0;i<10;i++) if(arr[i]%2==1) sum+=arr[i];
        cout<<"Child Process"<<endl;
        cout<<"Odd Sum is: "<<sum<<endl;
        cout<<endl;
    }
    else{
        int sum=0;
        for(int i=0;i<10;i++) if(arr[i]%2==0) sum+=arr[i];
        cout<<"Child Process"<<endl;
        cout<<"Even Sum is: "<<sum<<endl;
        cout<<endl;
    }
    return 0;
}