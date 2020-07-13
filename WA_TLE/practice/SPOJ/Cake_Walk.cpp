// https://www.spoj.com/problems/CKEWLK/
// TLE

#include <iostream>
#include <algorithm>
#include <math.h>
#define mod 1000000007
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,m;
    cin>>t>>m;
    long long n[t];
    for(int i=0;i<t;i++)
        cin>>n[i];
    sort(n,n+t);
    long long i=0,j=2,temp=2;
    while(n[i]<=2)
    {
        n[i]=m+m+n[i];
        ++i;
    }
    while(j<n[t-1])
    {
        if(j==n[i]-1)
        {
            n[i]=((temp*m)%mod) + m + n[i];
            ++i;
        }
        else
        {
            temp=(temp*2)%mod;
            ++j;
        }
    }
    long long sum=0;
    for(int i=0;i<t;i++)
    {
        int j=2;
        while(j<=sqrt(n[i]))
        {
            if(n[i]%j==0)
                n[i]/=j;
            else
                ++j;
        }
        sum=(sum+n[i])%mod;
    }
    cout<<"The President needs to pay "<<sum<<" dollar(s)";
    return 0;
}
