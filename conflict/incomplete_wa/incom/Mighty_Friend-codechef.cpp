#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,k,summ,sumt;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int m[(n+1)/2];
        int t[n/2];
        for(int i = 0; i < n; i++)
        {
            if(i%2==0)
            cin>>m[i/2];
            else
            cin>>t[i/2];
        }
        sort(m,m+((n+1)/2));
        sort(t,t+(n/2));
        summ=0;
        sumt=0;
        for(int i = 0; i < ((n+1)/2); i++)
        {
            //cout<<m[i]<<" ";
            if(i<k && i < (n/2))
            summ+=t[i];
            else
            summ+=m[((k>=((n+1)/2))?0:i-k)];
        }
        //cout<<endl;
        for(int i = 0; i < (n/2); i++)
        {
            //cout<<t[i]<<" ";
            if(i<k)
            sumt+=m[((n+1)/2)-1-i];
            else
            sumt+=t[i];
        }
        //cout<<endl;
        //cout<<summ<<" "<<sumt<<endl;
        if(sumt>summ)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}