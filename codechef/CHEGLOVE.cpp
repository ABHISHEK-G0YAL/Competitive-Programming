#include <iostream>
using namespace std;
int main()
{
    int t,n,i;
    bool f,b;
    cin>>t;
    while(t--)
    {
        f=true;b=true;
        cin>>n;
        int l[n],g[n];
        for(i=0;i<n;i++)
            cin>>l[i];
        for(i=0;i<n;i++)
            cin>>g[i];
        for(i=0;i<n;i++)
        {
            if(!(l[i]<=g[i]))
            {
                f=false;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(!(l[i]<=g[n-1-i]))
            {
                b=false;
                break;
            }
        }
        if(f && b)
        cout<<"both"<<endl;
        else if(f)
        cout<<"front"<<endl;
        else if(b)
        cout<<"back"<<endl;
        else
        cout<<"none"<<endl;
    }
}
