#include <iostream>
#define ull unsigned long long
using namespace std;

bool foo(ull a[],ull b[],ull n) {
    for(ull i = 0; i < n-2; i++) {
        if(a[i]<=b[i]) {
            ull x=b[i]-a[i];
            a[i]+=x;
            a[i+1]+=(2*x);
            a[i+2]+=(3*x);
        }
        else 
            return false;
    }
    if((a[n-2]==b[n-2]) && (a[n-1]==b[n-1]))
        return true;
    else
        return false;
}
int main() {
    ull t;
    cin>>t;
    while(t--) {
        ull n;
        cin>>n;
        ull a[n],b[n];
        for(ull i = 0; i < n; i++)
            cin>>a[i];
        for(ull i = 0; i < n; i++)
            cin>>b[i];
        if(foo(a,b,n))
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
    return 0;
}