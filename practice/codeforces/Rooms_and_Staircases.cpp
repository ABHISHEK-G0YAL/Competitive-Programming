// http://codeforces.com/contest/1244/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, first, last;
    cin >> t;
    while(t--) {
        char ch;
        cin >> n;
        first = 0;
        last = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ch;
            if(ch == '1') {
                if(first == 0)
                    first = i;
                last = i;
            }
        }
        first = n - first + 1;
        if(last != 0)
            cout << max(first, last) * 2 << endl;
        else
            cout << n << endl;
    }
}