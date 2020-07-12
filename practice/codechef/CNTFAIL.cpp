// https://www.codechef.com/problems/CNTFAIL
// wrong answer

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n;
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            cin>>x;
            s.insert(x);
        }
        if(s.size() == 1 and *s.begin() == 0)
            cout << n << endl;
        else if(s.size() == 1 and *s.begin() == n - 1)
            cout << 0 << endl;
        else if(s.size() == 2 and abs(*s.begin() - *next(s.begin())) == 1)
            cout << n - max(*s.begin(), *next(s.begin())) << endl;
        else
            cout << -1 << endl;
    }
}