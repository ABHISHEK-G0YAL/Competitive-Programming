#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll k, q, n, m;
    cin >> k >> q;
    while(q--) {
        cin >> n >> m;
        ll votes = n / k + 1;
        cout << ceil(double(m) / votes) << endl;
    }
}