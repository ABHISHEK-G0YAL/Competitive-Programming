// https://www.codechef.com/problems/PINS

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p=1;
        string q="1";
        cin>>n;
        int zeros=n/2;
        for(int i=0;i<zeros;i++)
            q+='0';
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}