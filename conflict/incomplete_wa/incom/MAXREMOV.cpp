#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
int cake[MAX];

int main() {
    int t,n,k; cin>>t;
    while(t--) {
        memset(cake,0,sizeof(cake));
        cin>>n>>k;
        int l,r;
        for(int i=0;i<n;i++) {
            cin>>l>>r;
            r+=1;
            cake[l]+=1;
            cake[r]-=1;
        }
        for(int i=1;i<MAX;i++)
            cake[i]+=cake[i-1];
        for(int i=1;i<11;i++)
            cout<<cake[i]<<" ";
        cout<<endl;
        
    }
}