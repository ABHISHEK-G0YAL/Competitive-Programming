// https://www.codechef.com/problems/CNTFAIL

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x, pass_c1, pass_c2, pass_max;
    cin >> t;
    while(t--) {
        cin >> n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> x;
            m[x] += 1;
        }
        if(m.size() == 1) {
            pass_c1 = (*m.begin()).first;
            if(pass_c1 == 0)
                cout << n << endl;
            else if(pass_c1 == n - 1)
                cout << 0 << endl;
            else
                cout << -1 << endl;
        }
        else if(m.size() == 2) {
            pass_c1 = (*m.begin()).first;
            pass_c2 = (*next(m.begin())).first;
            pass_max = max(pass_c1, pass_c2);
            if(abs(pass_c2 - pass_c1) == 1 and pass_max <= n - 1 and m[pass_max] == n - pass_max)
                cout << n - pass_max << endl;
            else
                cout << -1 << endl;
        }
        else
            cout << -1 << endl;
    }
}