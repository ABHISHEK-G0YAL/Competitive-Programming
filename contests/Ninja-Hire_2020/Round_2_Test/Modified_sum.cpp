// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/contests/Ninja-Hire_2020/Round_2_Test/Modified_sum.md

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class solution {
    ll dp[100005][3];
    ll solve(vector<ll> &a, ll idx, ll x, ll cur=0) {
        int n = a.size();
        if (idx == n)
            return 0;
        if (dp[idx][cur] != -1)
            return dp[idx][cur];
        ll ans = 0;
        if (cur == 0) {
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 0));
            ans = max(ans, x * a[idx] + solve(a, idx + 1, x, 1));
        }
        else if (cur == 1) {
            ans = max(ans, x * a[idx] + solve(a, idx + 1, x, 1));
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 2));
        }
        else
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 2));
        return dp[idx][cur] = ans;
    }
public:
    ll getSum(vector<ll> &a, ll x) {
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        ll sum = 0;
        for (ll i = 0; i < n; i++)
            sum = max(sum, solve(a, i, x));
        return sum;
    }
};

int main() {
    solution s;
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for(ll &i : a)
            cin >> i;
        cout << s.getSum(a, x) << endl;
    }
}