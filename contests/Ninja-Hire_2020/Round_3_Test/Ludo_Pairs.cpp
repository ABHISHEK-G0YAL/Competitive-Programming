// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/contests/Ninja-Hire_2020/Round_3_Test/Ludo_Pairs.md

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, ncs[1005], i, j;
    long long int p;
    cin >> t;
    while(t--) {
        memset(ncs, 0, 4020);
        cin >> n;
        vector<long long int> v(n);
        for(auto &x : v)
            cin >> x;
        cin >> p;
        for(auto &x : v)
            ++ncs[(x + p * 1000000000) % p];
        bool tru = (ncs[0] % 2 == 0);
        i = 1, j = p - 1;
        while(i < j)
            tru &= (ncs[i++] == ncs[j--]);
        if(i == j)
            tru &= (ncs[i] % 2 == 0);
        cout << (tru ? "true" : "false") << endl;
    }
}