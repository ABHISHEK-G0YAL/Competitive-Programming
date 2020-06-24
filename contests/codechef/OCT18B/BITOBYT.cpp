// https://www.codechef.com/OCT18B/problems/BITOBYT

#include <iostream>
#define ull unsigned long long
using namespace std;

int main()
{
    ull t,n,p;
    cin>>t;
    while(t--) {
        cin>>n; n-=1;
        p=1ULL<<(n/26);
        if((n%26)<2)
            cout<<p<<" 0 0"<<endl;
        else if((n%26)<10)
            cout<<"0 "<<p<<" 0"<<endl;
        else
            cout<<"0 0 "<<p<<endl;
    }
    return 0;
}