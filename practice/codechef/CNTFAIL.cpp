// https://www.codechef.com/problems/CNTFAIL
// wrong answer

#include <iostream>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int x,a[n]={0},i1,i2;
        for(int i=0;i<n;i++) {
            cin>>x; ++a[x];
        } x=0; bool fl=true; 
        for(int i=0;i<n;i++) {
            if(a[i]>0) {
                ++x;
                if(fl) {
                    i1=i;
                    fl=0;
                }
                else
                    i2=i;
            }
        }
        if(x==1 && a[n-1]==n)
            cout<<0<<endl;
        else if(x==2 && i2-i1==1)
            cout<<a[i2]<<endl;
        else
            cout<<-1<<endl;
    }
}