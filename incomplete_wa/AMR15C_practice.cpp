#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s,k;
    cin>>n;
    while(n--) {
        cin>>s>>k;
        int a[s+1];
        bool b[s+1]={0};
        if(k>s/2)
            cout<<-1<<endl;
        else {
            for(int i=1;i<=k;i++) {
                a[i]=i+k;
                b[i+k]=true;
            }
            for(int i=s;i>s-k;i--) {
                for(int j=0;;j++) {
                    if(b[i-k-j]==false) {
                        a[i]=i-k-j;
                        b[i-k-j]=true;
                        break;
                    }
                }
            }
            for(int i=k+1;i<=s-k;i++) {
                if(!b[i-k]) {
                    a[i]=i-k;
                    b[i-k]=true;
                }
                else {
                    a[i]=i+k;
                    b[i+k]=true;
                }
            }
            for(int i=1;i<=s;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
}
