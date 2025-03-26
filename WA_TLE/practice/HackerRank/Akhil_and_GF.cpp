// https://www.hackerrank.com/challenges/akhil-and-gf/problem

#include <bits/stdc++.h>
using namespace std;

long long modexp(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

long long repunit(long long n, long long m) {
    if(n == 1)
        return 1 % m;
    if(n % 2 == 0) {
        long long r = repunit(n / 2, m);
        long long t = modexp(10, n / 2, m);
        return (r * (t + 1)) % m;
    }
    else {
        long long r = repunit(n - 1, m);
        return (r * 10 + 1) % m;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long n;
        int m;
        cin >> n >> m;
        cout << repunit(n, m) << "\n";
    }
    return 0;
}