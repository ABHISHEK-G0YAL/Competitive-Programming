// https://www.facebook.com/hackercup/problem/2426282194266338/

#include <iostream>
using namespace std;

char canLeapfrog(string s) {
    int beta_frogs=0;
    for(int i=1;i<s.length();i++)
        beta_frogs+=(s[i]=='B');
    int unoccupied=s.length()-1-beta_frogs;
    return (unoccupied==1 && beta_frogs==1)?'Y':(unoccupied>0 && beta_frogs>1)?'Y':'N';
}
int main() {
    int t; cin>>t;
    for(int i=1;i<=t;i++) {
        string s;
        cin>>s;
        cout<<"Case #"<<i<<": "<<canLeapfrog(s)<<endl;
    }
}