// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
// Accepted

#include <iostream>
#include <cstdio>
#include <iomanip>      // std::setprecision
using namespace std;

int main() {
    // Complete the code.
    int a;long long b;char c;float d;double e;
    cin>>a>>b>>c>>d>>e;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<fixed<<setprecision(3)<<d<<endl;
    cout<<fixed<<setprecision(9)<<e<<endl;
    return 0;
}