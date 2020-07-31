// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/contests/Ninja-Hire_2020/Round_3_Test/Split_array.md

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while(t--) {
        unordered_map<int, int> mp;
        cin >> n;
        n *= 2;
        while(n--) {
            cin >> x;
            ++mp[x];
        }
        int yes = true;
        for(auto &p : mp)
            yes &= (p.second % 2 == 0);
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}