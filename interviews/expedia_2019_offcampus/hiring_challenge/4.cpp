#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int find(vector<int> &a,int A,int m) {
    int cnt = 0;
    int i = 0;
    while(i < a.size()) {
        cnt += (a[i++] / m);
        if(cnt >= A) return 1;
    }
    return 0;
}

int main() {
    int A = 2;
    vector<int> B = {1, 1};
    unordered_map<int,int> m;
    for(auto ele : B)
        m[ele]++;
    vector<int> arr;
    for(auto node : m)
        arr.push_back(node.second);
    sort(arr.begin(), arr.end(), greater<int>());
    int s = 1, e = arr[0];
    int ans = 0;
    // cout << find(arr, A, 1) << endl;
    while(s <= e) {
        int m = (s + e) / 2;
        if(find(arr, A, m)) {
            ans = max(ans, m);
            s = m + 1;
        }
        else
            e = m - 1;
    }
    cout << ans << endl;
}