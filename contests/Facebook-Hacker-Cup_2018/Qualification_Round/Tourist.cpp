// https://www.facebook.com/hackercup/problem/1632703893518337/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int t,n,k;
    long long v;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n>>k>>v;
        vector<string> places(n);
        for(int i=0;i<n;i++)
            cin>>places[i];
        int index=((v-1)*k)%n;
        cout<<"Case #"<<x<<":";
        int lastindex=index+k-1;
        if(lastindex>n-1)
        {
            lastindex%=n;
            for(int i=0;i<=lastindex;i++)
                cout<<" "<<places[i];
            for(int i=index;i<n;i++)
                cout<<" "<<places[i];
        }
        else
        {
            for(int i=index;i<=lastindex;i++)
                cout<<" "<<places[i];
        }
        cout<<endl;
    }
    return 0;
}