#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t,n,g;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        g=a[0];
        for(int i=1;i<n;i++)
        g=__gcd(g,a[i]);
        if(g==1)
        cout<<"0"<<endl;
        else
        cout<<"-1"<<endl;
    }
    return 0;
}
