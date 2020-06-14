#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n)
{
    int ans[100]={};
    int ca=0,temp,i,j,k;
    ans[99]=1;
    int a[100]={},b[100]={},c[100]={};
    for(int i=2;i<=n;i++)
    {
        temp=i;
        k=temp%10;
        temp/=10;
        j=temp%10;
        temp/=10;
        i=temp%10;
        for(int x=99;x>=0;x--)
        {
            temp=k*ans[x]+ca;
            a[x]=temp%10;
            ca=temp/10;
        }
        for(int x=98;x>=0;x--)
        {
            temp=j*ans[x]+ca;
            b[x]=temp%10;
            ca=temp/10;
        }
        for(int x=97;x>=0;x--)
        {
            temp=i*ans[x]+ca;
            c[x]=temp%10;
            ca=temp/10;
        }
        for(int x=99;x>=0;x--)
        {
            temp=a[x]+b[x]+c[x]+ca;
            ans[x]=temp%10;
            ca=temp/10;
        }
    }
    for(int x=0;x<100;x++)
        cout<<ans[x];
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

