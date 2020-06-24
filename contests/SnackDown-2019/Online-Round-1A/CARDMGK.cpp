// https://www.codechef.com/SNCK1A19/problems/CARDMGK/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,count=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=1;i<n;i++)
            if(v[i]<v[i-1])
                ++count;
        if( (count==0) || ( (count==1) && (v[n-1]<=v[0]) ) )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}