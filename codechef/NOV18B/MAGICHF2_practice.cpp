#include <iostream>
using namespace std;
int main() {
    long t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if(n%4==2 && k) {
            n=n/2+1;
            k--;
        }
        if(n!=2)
            while(n!=1 && k--)
                n=(n+1)/2;
        cout<<fixed<<1.0/n<<endl;
    }
}