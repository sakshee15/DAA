#include <iostream>
#include <vector>

using namespace std;

vector<int> merge2Array(vector<int> &lis1, vector<int> &lis2)
{
    vector<int> ans;
    int n1 = lis1.size(), n2 = lis2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (lis1[i] <= lis2[j])
        {
            ans.push_back(lis1[i]);
            i++;
        }
        else
        {
            ans.push_back(lis2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        ans.push_back(lis1[i]);
        i++;
    }
    while (j < n2)
    {
        ans.push_back(lis2[j]);
        j++;
    }
    return ans;
}

vector<int> mergeKArray(vector<vector<int>> &lis)
{
    vector<vector<int>> temp;
    while (lis.size() != 1)
    {
        temp.clear();
        for (int i = 0; i < lis.size(); i += 2)
        {
            if (i == lis.size() - 1)
            {
                temp.push_back(lis[i]);
            }
            else
            {
                temp.push_back(merge2Array(lis[i], lis[i + 1]));
            }
        }
        lis = temp;
    }
    return lis[0];
}

int main()
{
    vector<vector<int>> lis{{1, 5}, {2, 3, 7}, {0, 4, 6, 8}};
    vector<int> ans = mergeKArray(lis);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}