// http://codeforces.com/contest/1236/problem/B

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll power(int a, int n) {
    if(a == 0) return 0;
    if(n == 0) return 1;
    ll small = power(a, n / 2);
    ll ans = (small * small) % mod;
    if(n % 2)
        return (ans * a) % mod;
    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll pN = (power(2, m) - 1 + mod) % mod;
    ll ans = power(pN, n);
    cout << ans << endl;
}