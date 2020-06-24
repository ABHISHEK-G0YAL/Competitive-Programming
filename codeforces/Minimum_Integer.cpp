// http://codeforces.com/contest/1101/problem/A

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ll q,l,r,d; cin>>q;
    while(q--) {
        cin>>l>>r>>d;
        if(double(l)/d>1)
            cout<<d<<endl;
        else
            cout<<(ll)ceil(double(r+1)/d)*d<<endl;
    }
    return 0;
}