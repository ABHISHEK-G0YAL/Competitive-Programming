#include <bits/stdc++.h>
using namespace std;

int Count;

void nGoodSubSeq(int a[],int n,int m,int sum=0)
{
    //cout<<sum<<endl;
    if(n==0)
    {
        if(sum%m==0 && sum!=0)
            ++Count;
    }
    else
    {
        nGoodSubSeq(a+1,n-1,m,sum);
        nGoodSubSeq(a+1,n-1,m,sum+a[0]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            totalSum+=a[i];
        }
        if(totalSum%m==0)
            Count=-1;
        else
            Count=0;
        nGoodSubSeq(a,n,m);
        cout<<Count<<endl;
    }
    return 0;
}