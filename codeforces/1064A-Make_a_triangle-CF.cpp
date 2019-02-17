#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(((max({a,b,c})+1-(a+b+c-max({a,b,c})))>0)?(max({a,b,c})+1-(a+b+c-max({a,b,c}))):0)<<endl;
}