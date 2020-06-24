#include <iostream>
using namespace std;

int main()
{
    int t,m,x;
    long long n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        x=n%m;
        if(x%2==0)
        cout<<"EVEN"<<endl;
        else
        cout<<"ODD"<<endl;
    }
    return 0;
}