#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> nums(10, 0);
    while (1)
    {
        cout << "Enter number - ";
        int num;
        cin >> num;
        if (num == -1){
            int mx = INT_MIN;
            for (int i = 0; i < 10; i++)
            {
                mx = max(mx, nums[i]);
            }
            cout << "Max number among last 10 entered numbers is " << mx << endl;
        }
        else if (num == -2){
            float avg = 0;
            for (int n : nums)
            {
                avg += n;
            }
            avg /= 10;
            cout << "Average of the last 10 entered numbers is " << avg << endl;
        }
        else if (num == -3){
            exit(0);
        }
        else{
            nums.erase(nums.begin());
            nums.push_back(num);
        }
    }
    return 0;
}