#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> generateCardSeq(int n){
    int insert = 1;
    deque<int> q;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++){
        q.push_back(i);
    }
    while (!q.empty()){
        int p = q.front();
        q.pop_front();
        q.push_back(p);
        p = q.front();
        q.pop_front();
        ans[p] = insert;
        insert++;
    }
    return ans;
}

vector<int> generateCardSeqKSteps(int n, int k)
{
    int insert = 1;
    deque<int> q;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++){
        q.push_back(i);
    }
    while (!q.empty()){
        int p;
        for (int i = 0; i < k; i++){
            p = q.front();
            q.pop_front();
            q.push_back(p);
        }
        p = q.front();
        q.pop_front();
        ans[p] = insert;
        insert++;
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter no of cards - ";
    cin >> n;
    vector<int> ans = generateCardSeq(n);
    cout << "\nCard sequence is - ";
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n\n-----------------------------------------------------------";
    cout << "\n\nEnter no of cards - ";
    cin >> n;
    cout << "Enter no of cards to be moved in each step - ";
    cin >> k;
    vector<int> ans1 = generateCardSeqKSteps(n, k);
    cout << "\nCard sequence is - ";
    for (int i = 0; i < n; i++){
        cout << ans1[i] << " ";
    }
    return 0;
}
