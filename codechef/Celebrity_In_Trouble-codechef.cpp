#include <iostream>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int knows[n+1]={};
        int knownby[n+1]={};
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            ++knows[a];
            ++knownby[b];
        }
        int celebrity=0;
        for(int i = 1; i < n+1; i++)
        {
            if(knows[i]==0 && knownby[i]==n-1)
            {
                celebrity=i;
                break;
            }
        }
        if(celebrity)
            cout<<"alive "<<celebrity<<endl;
        else
            cout<<"dead"<<endl;
    }
    return 0;
}
