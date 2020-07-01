// https://www.codechef.com/SNCK1A19/problems/AVGMAT/
// partial points (50pts)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        char grid[n][m];
        vector<pair<int,int> > ij;
        int dist_cnt[n+m-1]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='1')
                    ij.push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<ij.size();i++) {
            for(int j=i+1;j<ij.size();j++) {
                ++dist_cnt[abs(ij[i].first-ij[j].first)+abs(ij[i].second-ij[j].second)];
            }
        }
        for(int i=1;i<n+m-1;i++)
            cout<<dist_cnt[i]<<" ";
        cout<<endl;
    }
    return 0;
}