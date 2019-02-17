#include<bits/stdc++.h>
using namespace std;
int main()
{
     int t;
     cin>>t;
     double p,q;
     while(t--)
     {
        double n,s;
        cin>>n>>s;
        if(n==1 && s>0)
            cout<<"-1"<<endl;
        else if (n==1)
            cout<<"1"<<endl;
        else {
            p=s*sqrt(n/2);
            q=-s*sqrt(n/2);
            cout<<setprecision(9)<<p<<" "<<q<<" ";
            for(int i=0;i<n-2;i++)
                cout<<0<<" ";
            cout<<"\n";
        }
     }
    return 0;
} 
