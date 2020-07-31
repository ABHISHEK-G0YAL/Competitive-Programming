// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/contests/Ninja-Hire_2020/Round_2_Test/Modified_sum.md

#include<bits/stdc++.h>
using namespace std;

bool canWin(vector<int> v, int p) {
    int n = v.size();
    int s = n - 1;
    v[p] += n;
    for(int i = 0; i < n; i++)
        if(p != i)
            v[i] += s--;
    int mx = 0;
    for(int &i : v)
        mx = max(mx, i);
    return v[p] >= mx;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int s = 0, e = n - 1, m;
    while(s != e) {
        m = (s + e) / 2;
        if(canWin(v, m))
            e = m;
        else
            s = m + 1;
    }
    cout << n - e << endl;
}