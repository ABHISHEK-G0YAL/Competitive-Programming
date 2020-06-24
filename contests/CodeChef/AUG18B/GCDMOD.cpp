// https://www.codechef.com/AUG18B/problems/GCDMOD/

#include <bits/stdc++.h>
#define ull unsigned  long long
#define mod 1000000007
using namespace std;

ull modd(ull a,ull b,ull m)
{
    int x=1000000;
    ull b1=b/x;
    ull b2=b%x;
    return (((((a*b1)%m)*x)%m)+((a*b2)%m))%m;
}

ull power(ull a,ull n,ull m)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return power(modd(a,a,m),n/2,m);
    else
        return modd(a,power(modd(a,a,m),n/2,m),m);
}

int main()
{
    ull t;
    cin>>t;
    while(t--)
    {
        ull a,b,n;
        cin>>a>>b>>n;
        ull m=a-b;
        if(m==0)
        {
            ull An=power(a%mod,n,mod);
            ull Bn=power(b%mod,n,mod);
            cout<<(An+Bn)%mod<<endl;
            continue;
        }
        else
        {
            ull An=power(a%m,n,m);
            ull Bn=power(b%m,n,m);
            cout<<__gcd(m,(An+Bn)%m)%mod<<endl;
        }
    }
    return 0;
}