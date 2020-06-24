// https://www.codechef.com/NOV18B/problems/PRDRG/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n%2)
            cout<<((1<<n)+1)/3<<" "<<(1<<n)<<" ";
        else
            cout<<((1<<n)-1)/3<<" "<<(1<<n)<<" ";
    }
} 
