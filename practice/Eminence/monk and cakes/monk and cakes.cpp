//int must be long long T_T

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<long long> nc,long long t)
{
  for(long long i=nc.size()-1;i>=0;i--)
  {
    // cout<<nc[i]-t<<endl;
    if(nc[i]-t>0)
      return false;
    else if(i>0)
      nc[i-1]+=(nc[i]-t);
  }
  return true;
}

int main()
{
  long long t;
  cin>>t;
  while(t--)
  {
    long long n,m;
    cin>>n>>m;
    // cout<<"n="<<n<<" m="<<m<<endl;
    vector<long long> l(m);
    vector<pair<long long,long long>> wc(n);
    for(long long i=0;i<m;i++)
      cin>>l[i];
    for(long long i=0;i<n;i++)
      cin>>wc[i].first;
    for(long long i=0;i<n;i++)
      cin>>wc[i].second;
      
    // for(long long i=0;i<n;i++)
    //   cout<<wc[i].first<<" ";
    // cout<<endl;
    // for(long long i=0;i<n;i++)
    //   cout<<wc[i].second<<" ";
    // cout<<endl;
    // for(long long i=0;i<m;i++)
    //   cout<<l[i]<<" ";
    // cout<<endl;
    
    sort(wc.begin(),wc.end());
    sort(l.begin(),l.end());
    
    // for(long long i=0;i<n;i++)
    //   cout<<wc[i].first<<" ";
    // cout<<endl;
    // for(long long i=0;i<n;i++)
    //   cout<<wc[i].second<<" ";
    // cout<<endl;
    // for(long long i=0;i<m;i++)
    //   cout<<l[i]<<" ";
    // cout<<endl;
    
    if(l[m-1]<wc[n-1].first)
      cout<<-1<<endl;
    else
    {
      vector<long long> nc(m);
      long long i=0,j=0;
      for(;i<m;i++)
        for(;wc[j].first<=l[i] && j<n;j++)
          nc[i]+=wc[j].second;
          
    //   for(long long i=0;i<m;i++)
    //     cout<<nc[i]<<" ";
    //   cout<<endl;
      
      long long min=nc[m-1],max=*max_element(nc.begin(),nc.end());
      while(min<max)
      {
        // cout<<"min="<<min<<" max="<<max<<endl;
        long long mid=(min+max)/2;
        // cout<<"mid="<<mid<<endl;
        // cout<<possible(nc,mid)<<endl;
        if(possible(nc,mid))
          max=mid;
        else
          min=mid+1;
      }
      cout<<min<<endl;
    }
  }
  return 0;
}