#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int count=n,freq=1;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        if(a[i-1]==a[i])
            ++freq;
        else if(a[i]<=a[i-1]+k)
        {
            count=count-freq;
            freq=1;
        }
        else
            freq=1;
    }
    cout<<count;
    return 0;
}