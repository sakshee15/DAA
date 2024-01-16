#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge(const vector<vector<int>> &partitions, int k)
{
    vector<int> result;
    vector<int> indices(k, 0);

    while (true)
    {
        int min = INT_MAX;
        int minIndex = -1;

        // Find the min element among the current indices of each partition
        for (int i = 0; i < k; ++i)
        {
            if (indices[i] < partitions[i].size() && partitions[i][indices[i]] < min)
            {
                min = partitions[i][indices[i]];
                minIndex = i;
            }
        }

        // If no min element is found, we are done
        if (minIndex == -1)
        {
            break;
        }

        // Move the index for the partition we took the min element from
        ++indices[minIndex];

        // Add the min element to the result
        result.push_back(min);
    }

    return result;
}

void k_way_merge_sort(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n <= 1)
    {
        return;
    }

    int partition_size = n / k;
    int remaining_elements = n % k;

    vector<vector<int>> partitions;

    // Divide the array into k partitions
    int last = 0;
    for (int i = 0; i < k; i++)
    {
        vector<int> partition;
        int elements_in_partition = partition_size + (i >= k - remaining_elements ? 1 : 0);
        for (int j = 0; j < elements_in_partition; j++)
        {
            partition.push_back(arr[j + last]);
        }
        last += elements_in_partition;
        partitions.push_back(partition);
    }

    // Recursively sort each partition
    for (int i = 0; i < k; ++i){
        k_way_merge_sort(partitions[i], k);
    }

    // Merge the sorted partitions
    arr = merge(partitions, k);
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int k = 3;

    cout << "Original array: ";
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    k_way_merge_sort(arr, k);

    cout << "Sorted array: ";
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
