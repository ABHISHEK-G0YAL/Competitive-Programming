// https://www.hackerrank.com/challenges/equality-in-a-array/problem
// Accepted

#include <bits/stdc++.h>
#define max(x) *max_element(x,x+101)
using namespace std;

int main() {
    int n,x; cin>>n;
    int N=n,dp[101]={0};
    while(n--) {
        cin>>x;
        ++dp[x];
    } cout<<N-max(dp)<<endl;
}