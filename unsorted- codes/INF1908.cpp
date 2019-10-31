#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << n / 10 << (n + k) % 10 << endl;
    }
}
