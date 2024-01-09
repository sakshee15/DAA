// Write a C program for merge sort and find its time complexity
// eg - 38 27 43 3 9 82 10
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &lis, int low, int mid, int high) {
    vector<int> temp = lis;
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (temp[i] <= temp[j]) {
            lis[k] = temp[i];
            i++;
        } else {
            lis[k] = temp[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        lis[k] = temp[i];
        i++;
        k++;
    }
    while (j <= high) {
        lis[k] = temp[j];
        k++;
        j++;
    }
}


void mergeSort(vector<int> &lis, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(lis, low, mid);
    mergeSort(lis, mid + 1, high);
    merge(lis,low,mid,high);
}


int main(){
    vector<int> lis{38, 27, 43, 3, 9, 82, 10};
    mergeSort(lis,0,lis.size()-1);
    for(int i=0;i<lis.size();i++){
        cout<<lis[i]<<" ";
    }
    return 0;
}
