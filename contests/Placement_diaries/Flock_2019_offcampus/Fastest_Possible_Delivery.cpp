// https://codeforces.com/blog/entry/73184

#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
#define ll long long int
ll pet[N];
ll val[N];
ll n, d, p, k;

ll dp[N][N];

ll go(int pos, ll petrol){
    if(pos == d) return 0;
    ll &ans = dp[pos][petrol];
    if(ans != -1) return ans;
    ans = numeric_limits<int>::max();
    ans = min(ans, go(pos + 1, max(0LL, petrol - 1)) + ((petrol == 0) ? 5 : 1));
    if(pet[pos]){
       ans = min(ans, go(pos + 1, max(0LL, petrol) + pet[pos] - 1) + 1 + k);
    }
    return ans;
}

int main(){
    cin >> n >> d >> p >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pet[x] = 1;
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        val[i] = x;
    }
    int pt = 0;
    for(int i = 0; i < 5001; i++){
        if(pet[i]){
            pet[i] = val[pt++];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, p);
}