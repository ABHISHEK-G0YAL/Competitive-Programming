#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,count=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x%m==0)
                ++count;
        }
        cout<<int(pow(2,count)-1)<<endl;
    }
    return 0;
}