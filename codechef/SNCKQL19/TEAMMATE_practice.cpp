#include <bits/stdc++.h>
#define mod 1000000007
#define max 1000001
#define ui unsigned int
#define ll long long
#define ull unsigned long long
using namespace std;
ui num[max];

ull makepair(ll n) {
    ull ans=1;
    n=n-1;
    while(n>0) {
        ans=(ans*n)%mod;
        n=n-2;
    }
    return ans;
}

int main() {
    ui t;
    cin>>t;
    while(t--) {
        ui n;
        cin>>n;
        ull ans=1;
        vector<ui> fre;
        memset(num,0,sizeof(num));
        for(ui i=0;i<n;i++) {
            ui x;
            cin>>x;
            ++num[x];
        }
        for(ui i=max-1;i>0;i--)
            if(num[i]!=0)
                fre.push_back(num[i]);
        for(ui i=0;i<fre.size();i++) {
            if(fre[i]&1U) {
                ans=(ans*fre[i+1])%mod;
                fre[i]=fre[i]+1;
                fre[i+1]=fre[i+1]-1;
            }
            ans=(ans*makepair(fre[i]))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define mod 1000000007
// #define max 1000001
// #define ui unsigned int
// using namespace std;
// ui num[max];

// int main()
// {
//     ui t,ans=1;
//     cin>>t;
//     while(t--) {
//         ui n;
//         cin>>n;
//         memset(num,0,sizeof(num));
//         for(int i = 0; i < n; i++) {
//             ui x;
//             cin>>x;
//             ++num[x];
//         }
//         for(int i = 0; i < max; i++) {
//             if(num[i]!=0)
//                 ans=(ans*num[i])%mod;
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }