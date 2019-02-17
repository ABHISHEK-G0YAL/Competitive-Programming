#include <bits/stdc++.h>
#define M 100001
using namespace std;

main()
{
    int t,q,x,y,mlen,nlen;
    cin>>t;
    string m,n;
    while(t--){
        cin>>m>>n>>q;
        mlen=m.length();
        nlen=n.length();
        vector<bitset<M> > dp(nlen+1);
        for(int i=0;i<mlen;i++)
            dp[0][i+1]=m[i]-'0';
        for(int i=0;i<nlen;i++)
            dp[i+1][0]=n[i]-'0';
        for(int i=1;i<=nlen;i++)
            for(int j=1;j<=mlen;j++)
                dp[i][j]=(dp[i-1][j] & dp[i][j-1])?0:1;
        while(q--){
            cin>>x>>y;
            cout<<dp[x][y];
        }
        cout<<endl;
    }
    return 0;
} 
