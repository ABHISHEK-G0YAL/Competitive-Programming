#include <iostream>
using namespace std;

int main()
{
    unsigned long long a;
    cin>>a;
    a%=6;
    if(a==1 || a==3 || a==0)
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}