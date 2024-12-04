#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int pid[n];
    cout<<"Enter process id's: ";
    for(int i=0;i<n;i++) cin>>pid[i];

    int burst[n];
    cout<<"Enter burst times: ";
    for(int i=0;i<n;i++) cin>>burst[i];

    int priority[n];
    cout<<"Enter priority values: ";
    for(int i=0;i<n;i++) cin>>priority[i];

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(priority[j]>priority[i]){
                swap(priority[i],priority[j]);
                swap(burst[i],burst[j]);
                swap(pid[i],pid[j]);
            }
        }
    }

    int waiting[n];
    waiting[0]=0;
    for(int i=1;i<n;i++) waiting[i]=waiting[i-1]+burst[i-1];

    int turnAround[n];
    for(int i=0;i<n;i++) turnAround[i]=burst[i]+waiting[i];

    cout<<"Order of Execution of Process by Priority: ";
    for(int i=0;i<n;i++) cout<<pid[i]<<endl;

    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<"Waiting Time: "<<waiting[i]<<endl;
        cout<<"Burst Time: "<<burst[i]<<endl;
        cout<<"TurnAround Time: "<<turnAround[i]<<endl;
        cout<<endl;
    }

    int totalTAT=0;
    for(int i=0;i<n;i++) totalTAT+=turnAround[i];
    cout<<"Average Turn Around Time: "<<totalTAT/n<<endl;

    int totalWaiting=0;
    for(int i=0;i<n;i++) totalWaiting+=waiting[i];
    cout<<"Average Waiting Time: "<<totalWaiting/n<<endl;

    return 0;
}