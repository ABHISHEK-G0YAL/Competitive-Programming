#include <iostream>
#include <string>
#define ui unsigned int
using namespace std;

int main() {
    ui t;
    cin >> t;
    string n;
    bool start;
    for(ui i=1;i<=t;i++) {
        cin>>n;
        cout<<"Case #"<<i<<": ";
        for(ui x=0;x<n.length();x++) {
            if(n[x]=='4')
                cout<<'3';
            else
                cout<<n[x];
        } cout<<" ";
        start=false;
        for(ui x=0;x<n.length();x++) {
            if(n[x]=='4' && (start=true))
                cout<<'1';
            else if(start)
                cout<<'0';
        } cout<<endl;
    }
}