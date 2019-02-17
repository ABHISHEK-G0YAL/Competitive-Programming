#include <iostream>
#include <algorithm>
#define mod 1000000007
#define MAX 1001
#define ull unsigned long long
using namespace std;

ull C[MAX][MAX]={};
ull mima[MAX][MAX]={};

ull pow(ull x,ull y) {
    ull res=1;  
    while(y>0) {
        if(y&1)
            res=(res*x)%mod;
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}

int main() {
    for (ull i=0;i<MAX;i++) {
        for (ull j=0;j<=i;j++) {
            if (j==0 || j==i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    for (ull mi=0;mi<MAX;mi++) {
        for (ull ma=mi;ma<MAX;ma++) {
            ull b_s=0;
            for(int k=0;k<=mi;k++)
                b_s=(b_s+(C[mi][k]*C[ma][k]))%mod;
            mima[mi][ma]=b_s;
        }
    }
    ull t;
    cin>>t;
    while(t--) {
        ull n;
        cin>>n;
        ull a[n],b_s=0;
        for(ull i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(ull i=0;i<n;i++) {
            for(ull j=i+1;j<n;j++) {
                if(a[i]!=a[j]) {
                    ull mi=min(i,n-1-j),ma=max(i,n-1-j);
                    b_s=(b_s+mima[mi][ma])%mod;
                }
            }
        }
        cout<<(mod+pow(2,n)-b_s-1)%mod<<endl;
    }
    return 0;
}