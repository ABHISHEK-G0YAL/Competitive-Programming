#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

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
        vector<ull>::iterator low=lower_bound(fx.begin(),fx.end(),n);
        vector<ull>::iterator up=upper_bound(fx.begin(),fx.end(),n);
        cout<<min(*up-n,n-*low)<<endl;
    }
    return 0;
}
