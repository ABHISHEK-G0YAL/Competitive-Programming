#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool chk(ll m,vector<ll> &a,vector<ll> &b,ll &candies) {
    for(int i=0;i<a.size();i++)
        if(candies/b[i]<a[i])
            m-=(a[i]-(candies/b[i]));
    if(m<0)
        return false;
    else
        return true;
}
int main() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++)
        cin>>b[i];
    ll candies=500000000000000000,min=0,max=1000000000000000000;
    while(min<max) {
        if(chk(m,a,b,candies))
            max=candies;
        else
            min=candies+1;
        candies=(min+max)/2;
    }
    cout<<candies<<endl;
}