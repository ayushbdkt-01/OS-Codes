#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of page refrences: ";
    cin>>n;
    
    int incomingStream[n];
    cout<<"Enter page refrences: ";
    for(int i=0;i<n;i++) cin>>incomingStream[i];

    int pageFault=0;
    int frames=3;

    int temp[frames];
    for(int i=0;i<frames;i++) temp[i]=-1;

    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<frames;j++){
            if(incomingStream[i] == temp[j]) s++, pageFault--;      
        }
        pageFault++;
        if(pageFault<=frames && s==0) temp[i]=incomingStream[i];
        else if(s==0) temp[(pageFault-1)%frames] = incomingStream[i];

        cout << "Stream: " << incomingStream[i] << endl;
        for(int j = 0; j < frames; j++) {
            if(temp[j] == -1) cout << "-\t"; 
            else cout << temp[j] << "\t";
        }
        cout << endl;
    }
    cout << "Total Page Faults: " << pageFault << endl;
    return 0;
}