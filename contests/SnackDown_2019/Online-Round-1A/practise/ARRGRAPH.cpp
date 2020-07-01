// https://www.codechef.com/problems/ARRGRAPH

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool flag[51];
    int t;
    cin>>t;
    while(t--) {
        bool chk=true,forty7=true;
        memset(flag,0,sizeof(flag));
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i]==47)
            	forty7=false;
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(__gcd(a[i],a[j])==1) {
                    flag[a[i]]=true;
                    flag[a[j]]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(flag[a[i]]==false)
                chk=false;
        if(chk || n==1) {
            cout<<0<<endl;
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        else {
            cout<<1<<endl;
            if(forty7)
            	a[0]=47;
            else
            	a[0]=43;
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}