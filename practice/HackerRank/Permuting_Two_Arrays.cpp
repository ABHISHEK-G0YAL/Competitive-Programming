// https://www.hackerrank.com/challenges/two-arrays/problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int &i : a)
            cin >> i;
        for(int &i : b)
            cin >> i;
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        bool valid = true;
        for(int i = 0; i < n and valid; i++)
            valid = a[i] + b[i] >= k;
        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
