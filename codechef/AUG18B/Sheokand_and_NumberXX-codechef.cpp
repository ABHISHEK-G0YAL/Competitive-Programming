#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void modified_binary_search(vector<ull> &fx,ull n,ull l,ull r,ull &low,ull &up)
{
    if((r-l)==1)
    {
        low=fx[l];
        up=fx[r];
    }
    else
    {
        ull mid=(r+l)/2;
        if(n>=fx[mid])
            modified_binary_search(fx,n,mid,r,low,up);
        else
            modified_binary_search(fx,n,l,mid,low,up);
    }
}

int main()
{
    const ull one=1;
    vector<ull> fx;
    for(ull x=0;x<=30;x++)
        for(ull y=x+1;y<=30;y++)
            fx.push_back((one<<x)+(one<<y));
    sort(fx.begin(),fx.end());
    ull t;
    cin>>t;
    while(t--)
    {
        ull n;
        cin>>n;
        ull low,up;
        modified_binary_search(fx,n,0,fx.size()-1,low,up);
        cout<<min(up-n,n-low)<<endl;
    }
    return 0;
}
