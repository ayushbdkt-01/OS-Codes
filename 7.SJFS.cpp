#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int burst[n];
    cout<<"Enter burst times of processes: ";
    for(int i=0;i<n;i++) cin>>burst[i];
    sort(burst, burst+n);

    int waiting[n];
    waiting[0]=0;
    for(int i=1;i<n;i++) waiting[i]=waiting[i-1]+burst[i-1];

    int turnAround[n];
    for(int i=0;i<n;i++) turnAround[i]=burst[i]+waiting[i];

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