// http://codeforces.com/contest/990/problem/A

#include <iostream>
using namespace std;
 
int main()
{
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    long long x=n%m;
    if((x*b)<((m-x)*a))
    cout<<x*b;
    else
    cout<<(m-x)*a;
    return 0;
}