// https://www.hackerrank.com/challenges/largest-permutation/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> &largestPermutation(int k, vector<int> &a) {
    int i = 0;
    unordered_map<int, int> mp;
    for(auto &x : a)
        mp[x] = i++; 
    i = 0;
    while(i < a.size() and k > 0) {
        auto it = mp.find(a.size() - i);
        if(it->second != i) {
            swap(a[i], a[it->second]);
            mp[a[it->second]] = it->second;
            mp[a[i]] = i;
            k -= 1;
        }
        i += 1;
    }
    return a;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    for(auto &i : largestPermutation(k, a))
        cout << i << " ";
}
