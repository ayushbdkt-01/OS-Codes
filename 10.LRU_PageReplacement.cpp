#include<bits/stdc++.h>
using namespace std;


int find_LRU_index(int time[], int n){
    int mini=time[0];
    int minIndex=0;
    for(int i=0;i<n;i++){
        if(time[i]<mini){
            mini=time[i];
            minIndex=i;
        }
    }
    return minIndex;
}


int main(){
    int pageSize;
    cout<<"Enter page size: ";
    cin>>pageSize;

    int frameSize;
    cout<<"Enter frame size: ";
    cin>>frameSize;

    int pages[pageSize];
    int frames[frameSize];
    int pageFaults=0;

    cout<<"Enter refrence string: ";
    for(int i=0;i<pageSize;i++) cin>>pages[i];

    for(int i=0;i<frameSize;i++) frames[i]=-1;

    int count=0;

    int time[frameSize];
    for(int i=0;i<frameSize;i++) time[i]=0;

    for(int i=0;i<pageSize;i++){
        int currPage=pages[i];
        bool pageFound=false;
        for(int j=0;j<frameSize;j++){
            if(frames[j]==currPage){
                pageFound=true;
                time[j]=count;
                count++;
                break;
            }
        }
        if(pageFound==false){
            int position=find_LRU_index(time,frameSize);
            frames[position]=currPage;
            time[position]=count;
            count++;
            pageFaults++;
        }
        cout<<"Current Frames: ";
        for(int i=0;i<frameSize;i++) cout<<frames[i]<<" ";
        cout<<endl;
    }
    cout<<"Total page faults: "<<pageFaults<<endl;


    return 0;
}