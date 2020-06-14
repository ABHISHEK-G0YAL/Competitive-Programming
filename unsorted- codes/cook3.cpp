#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main() {
    int t;
    ull l, r, ans;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        int i = 63;
        ans = 0;
        while(i >= 0) {
            if((l & (1ULL << i)) == (r & (1ULL << i)))
                ans += r & (1ULL << i);
            else
                break;
            i--;
        }
        while(i >= 0) {
            ans += 1ULL << i;
            i--;
        }
        cout << ans << endl;
    }
}