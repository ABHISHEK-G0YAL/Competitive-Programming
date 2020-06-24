// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da

#include <iostream>
#include <string>
#define ui unsigned int
using namespace std;

int main() {
    ui t,n;
    cin >> t;
    string p;
    for(ui i=1;i<=t;i++) {
        cin >> n >> p;
        cout<<"Case #"<<i<<": ";
        for(ui x=0;x<p.length();x++) {
            if(p[x]=='E')
                cout<<'S';
            else
                cout<<'E';
        } cout<<endl;
    }
}