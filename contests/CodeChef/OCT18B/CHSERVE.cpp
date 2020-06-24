// https://www.codechef.com/OCT18B/problems/CHSERVE

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int p1,p2,k;
        cin>>p1>>p2>>k;
        if(((p1+p2)/k)%2==0)
            cout<<"CHEF"<<endl;
        else
            cout<<"COOK"<<endl;
    }
}