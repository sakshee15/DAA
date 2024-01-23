#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<unistd.h>
using namespace std;


vector<int> generateRandom(vector<int> &ans){
     int last_index=ans.size()-1;
    while(last_index>0){
    	 srand(time(0));
        int rand_index = rand()% (last_index+1);
        swap(ans[rand_index],ans[last_index]);
        last_index--;
    }
    return ans;   	
}

int updatedMax(vector<int> &ans){
   int update=0;
    int mx=INT_MIN;
    for(int i=0;i<ans.size();i++){
    	if(ans[i]>mx){
          mx=ans[i];
          update++;
	}
    }
    return update;	
}

int average(vector<int> &maxArray){
	long long sum=0;
	for(int i=0;i<maxArray.size();i++){
		sum+=maxArray[i];
	}
	return static_cast<int>(sum)/maxArray.size();
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> ans,maxArray;
    for(int i=1;i<=n;i++){
        ans.push_back(i);
    }
     int time=1000;
    while(time){
    	generateRandom(ans);
    	 for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    int update = updatedMax(ans);
    cout<<"Max is updated: "<<update<<" times"<<endl;
    cout<<endl;
    maxArray.push_back(update);
    //sleep(0.005);
     time--;
    }
    int avg = average(maxArray);
    cout<<"Average is : "<<avg<<endl; 
     
   
    return 0;
}
