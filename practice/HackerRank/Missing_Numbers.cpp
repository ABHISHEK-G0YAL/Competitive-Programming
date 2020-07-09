// https://www.hackerrank.com/challenges/missing-numbers/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

template <typename T> 
T input() {
    T temp;
    cin >> temp;
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> s_set;
    for(int i = 0; i < n; i++)
        s_set.push_back(input<int>());
    sort(s_set.begin(), s_set.end());
    int m;
    cin >> m;
    vector<int> c_set;
    for(int i = 0; i < m; i++)
        c_set.push_back(input<int>());
    sort(c_set.begin(), c_set.end());
    vector<int> d_set(c_set.size() - s_set.size());
    set_difference(c_set.begin(),c_set.end(), s_set.begin(),s_set.end(), d_set.begin());
    set<int> D_set(d_set.begin(), d_set.end());
    for(auto i : D_set) cout << i << " ";
    return 0;
}
