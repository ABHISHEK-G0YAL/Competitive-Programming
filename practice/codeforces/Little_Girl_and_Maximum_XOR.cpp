// http://codeforces.com/contest/276/problem/D

#include <bits/stdc++.h>
using namespace std;
 
long long int maximizingXor(long long int l, long long int r) {
    return (1LL << int(log2(l ^ r) + 1)) - 1;
}
 
int main() {
    long long int l, r;
    cin >> l >> r;
    cout << maximizingXor(l, r);
}