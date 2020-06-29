// https://www.codechef.com/JUNE19A/problems/SUMAGCD/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maxSubGCD(set<int> s) {
    auto last=s.end();
    int MAX1=*(--last);
    if(s.size()==1) return 2*MAX1;
    int MAX2=*(--last);
    if(s.size()==2) return MAX1+MAX2;
    int gcd=*(--last);
    s.erase(MAX1);
    s.erase(MAX2);
    s.erase(gcd);
    for(auto i:s) gcd=__gcd(gcd,i);
    return max(MAX1+__gcd(gcd,MAX2),MAX2+__gcd(gcd,MAX1));
}
int main() {
    int t; cin>>t;
    while(t--) {
        int n,x; cin>>n;
        set<int> s;
        for(int i=0;i<n;i++) {
            cin>>x;
            s.insert(x);
        } cout<<maxSubGCD(s)<<endl;
    }
}