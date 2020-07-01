// https://www.codechef.com/problems/CKWLK

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool divisibleBy10rN(ll n) {
    while(n % 10 == 0)
        n /= 10;
    return n == 1;
}

bool isNDollarsAchievable(ll n) {
    if(divisibleBy10rN(n))
        return true;
    while(n % 20 == 0) {
        n /= 20;
        if(divisibleBy10rN(n))
            return true;
    }
    return n == 1;
}

int main() {
    int t;
    ll n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (isNDollarsAchievable(n) ? "Yes" : "No") << endl;
    }
}