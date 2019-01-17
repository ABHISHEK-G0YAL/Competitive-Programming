#include <bits/stdc++.h>
using namespace std;

int Count;

void nGoodSubSeq(int a[],int m,int &maxSum,int i=0,int sum=0)
{
    //cout<<sum<<endl;
    if(i==1001)
    {
        if(sum%m==0 && sum!=0 && sum!=maxSum)
            ++Count;
    }
    else
    {
        for(int b=0;b<=a[i];b++)
            nGoodSubSeq(a,m,maxSum,i+1,sum+(b*i));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,maxSum=0;
        cin>>n>>m;
        int a[1001]={0};
        for(int i=0;i<n;i++)
        {
            cin>>x;
            maxSum+=x;
            ++a[x];
        }
        Count=0;
        nGoodSubSeq(a,m,maxSum);
        cout<<Count<<endl;
    }
    return 0;
}