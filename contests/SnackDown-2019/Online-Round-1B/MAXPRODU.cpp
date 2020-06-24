// https://www.codechef.com/SNCK1B19/problems/MAXPRODU/

#include <iostream>
#define mod 1000000007
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        if((k*(k+1))/2 > n) {
            cout<<-1<<endl;
            continue;
        }
        ll prod=1,num[k],start=(n/k)-(k/2),dist=n%k;
        for(ll i=0;i<k;i++) {
            if(k%2==0 && start==(n/k))
                i=i-1;
            else
                num[i]=start;
            ++start;
        }
        if(k%2) {
            ll end=k-1;
            while(dist--) {
                num[end]+=1;
                end--;
            }
        }
        else {
            ll rem_dist=dist;
            for(ll i=0;i<dist;i++) {
                if(i==k/2)
                    break;
                --rem_dist;
                num[((k/2)-1)-i]+=1;
            }
            if(rem_dist>0) {
                dist=rem_dist;
                ll end=k-1;
                while(dist--) {
                    num[end]+=1;
                    end--;
                }
            }
        }
        for(ll i=0;i<k;i++) {
            prod=(prod*num[i])%mod;
            prod=(prod*(num[i]-1))%mod;
        }
        cout<<prod<<endl;
    }
    return 0;
}