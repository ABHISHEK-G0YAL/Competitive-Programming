// https://www.facebook.com/hackercup/problem/656203948152907/

#include <iostream>
using namespace std;

char canLeapfrog(string s) {
    int sum=0;
    bool dot=false;
    for(int i=1;i<s.length();i++) {
        sum+=(s[i]=='B'?1:-1);
        dot=(s[i]=='.'?true:dot);
    } return (sum>=0 && dot)?'Y':'N';
}
int main() {
    int t; cin>>t;
    for(int i=1;i<=t;i++) {
        string s;
        cin>>s;
        cout<<"Case #"<<i<<": "<<canLeapfrog(s)<<endl;
    }
}