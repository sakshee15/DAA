//Josephus problem - array based approach
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of people - ";
    cin>>n;
    vector<int> arr(n,1);
    int noOfDead=0;
    bool kill=false;
    while(noOfDead<n-1){
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                if(kill){
                    arr[i]=0;
                    noOfDead++;
                }
                kill=!kill;
            }
            
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]){
            cout<<"\nSurvivor is at position : "<<i+1<<endl;
        }
    }
       
   return 0;
}


