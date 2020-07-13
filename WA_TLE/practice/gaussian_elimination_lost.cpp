#include <bits/stdc++.h>
using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;

ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}

ull gaussian_elimination(vector<ull> v)
{
    sort(v.rbegin(),v.rend());
    int n=v.size();
    int ind=0;
    for(int bit=log2(v[0]);bit>=0;bit--)
    {
        int x=ind;
        while(x<n && check_bit(v[x],bit)==0)
          x++;
        if(x==n)
          continue;
        swap(v[ind],v[x]);
        for(int j=0;j<n;j++)
        {
            if(j!=ind&&check_bit(v[j],bit))
                v[j]^=v[ind];
        }
        ind++;
    }
    ull ans=v[0];
    for(int i=1;i<n;i++)
        ans=max(ans,ans^v[i]);
    return ans;
}
int main()
{
    vector<ull> v;
    int i,n;
    scanf("%d",&n);
    ull x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<gaussian_elimination(v)<<"\n";
return 0;
}