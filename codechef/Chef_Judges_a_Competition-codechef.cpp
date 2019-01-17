#include <iostream>
using namespace std;

int main()
{
    int t,n,asum,bsum,max;
    cin>>t;
    while(t--)
    {
        asum=0;
        bsum=0;
        cin>>n;
        int a[n],b[n];
        max=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            asum+=a[i];
            if(a[i]>max)
                max=a[i];
        }
        asum-=max;
        max=0;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            bsum+=b[i];
            if(b[i]>max)
                max=b[i];
        }
        bsum-=max;
        if(asum<bsum)
            cout<<"Alice"<<endl;
        else if(bsum<asum)
            cout<<"Bob"<<endl;
        else
            cout<<"Draw"<<endl;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
    int t,n,asum,bsum,maxa,maxb;
    cin>>t;
    while(t--)
    {
        asum=0;
        bsum=0;
        maxa=0;
        maxb=0;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
            asum+=a[i];
        for(int i=0;i<n;i++)
            bsum+=b[i];
        for(int i=0;i<n;i++)
            if(a[i]>maxa)
                maxa=a[i];
        for(int i=0;i<n;i++)
            if(b[i]>maxb)
                maxb=b[i];
        asum-=maxa;
        bsum-=maxb;
        if(asum<bsum)
            cout<<"Alice"<<endl;
        else if(bsum<asum)
            cout<<"Bob"<<endl;
        else
            cout<<"Draw";
    }
    return 0;
}
*/