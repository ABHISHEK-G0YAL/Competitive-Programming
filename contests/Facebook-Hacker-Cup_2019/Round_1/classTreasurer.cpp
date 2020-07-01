// https://www.facebook.com/hackercup/problem/2448144345414246/
// Incorrect Submission

#include <bits\stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll exp(ll a,ll b,ll m) {
	ll res=1;
	while(b) {
		if(b&1L) {
			res*=a;
			res%=m;
		} a*=a;
		a%=m;
		b>>=1;
	} return res;
}
int main() {
    ll t,n,k;
    string s;
    cin>>t;
    for(ll x=1;x<=t;x++) {
		cin>>n>>k>>s;
		ll countB=0,cost=0;
		for(ll i=s.length()-1;i>=0;i--) {
			if(s[i]=='B') countB++;
			else countB--;
			if(countB<0) countB=0;
			if(countB==(k+1)) {
				cost+=exp(2,i+1,mod);
				cost%=mod;
				countB-=2;
			}
		} cout<<"Case #"<<x<<": "<<cost<<endl;
	}
}