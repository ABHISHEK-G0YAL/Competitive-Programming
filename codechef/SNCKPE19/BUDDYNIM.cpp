#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        bool flag=true;
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i]==0) {
                n=n-1;
                i=i-1;
            }
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]==0) {
                m=m-1;
                i=i-1;
            }
        }
        if(n==m) {
            sort(a,a+n);
            sort(b,b+m);
            for(int i=0;i<n;i++) {
                if(a[i] != b[i]) {
                    flag=false;
                }
            }
            if(flag)
                cout<<"Bob"<<endl;
            else
                cout<<"Alice"<<endl;
        }
        else
            cout<<"Alice"<<endl;
    }
}