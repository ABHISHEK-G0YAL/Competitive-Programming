#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x,cnt;
        cin>>n;
        vector<vector<int> > v(n+1);
        for(int i=1;i<=n;i++) {
            cin>>x;
            v[x].push_back(i);
        }
        for(int i=1;i<=n;i++) {
            cnt=0;
            for(int j=0;j<v[i].size();j++) {
                if(v[v[i][j]].size()>0)
                    ++cnt;
                if(cnt>1)
                    goto happy;
            }
        }
        cout<<"Poor Chef"<<endl;
        continue;
        happy:cout<<"Truly Happy"<<endl;
    }
} 
