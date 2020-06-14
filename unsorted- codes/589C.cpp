#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int mpow(int x) {
    if(x == 0)
        return 1;
    long long hans = mpow(x / 2);
    long long ans = (hans * hans) % mod;
    if(x % 2)
        return (2 * ans) % mod;
    else
        return ans;
}

vector<int> pFac(int x) {
    int i = 2;
    vector<int> pFactors;
    while(i <= sqrt(x)) {
        while(x % i == 0) {
            if(pFactors.empty() or pFactors.back() != i)
                pFactors.push_back(i);
            x /= i;
        }
    }
    if(x != 1)
        pFactors.push_back(x);
    return pFactors;
}

int main() {
    ll x, n;
    cin >> x >> n;
    ll finalProd = 1;
    vector<int> pFactors = pFac(x);
    for(int fac : pFactors) {
        while(n / fac > 1) {
            finalProd = finalProd * 
        }
    }
}