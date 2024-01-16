#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot  = arr[high];
    int  i =low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(vector<int> &arr,int low,int high){
     if(low < high){
        int pivot  = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
     }
}
int main(){
    vector<int> arr = {38,92,35,65,12,50,20};
     cout << "Original array: ";
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    quicksort(arr,0,arr.size()-1);

    cout << "Sorted array: ";
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
