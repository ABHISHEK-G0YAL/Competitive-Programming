#include <iostream>
using namespace std;

main()
{
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        if(((n>0) && (m>0) && (n-1)%x==0) && ((m-1)%y==0))
            cout<<"Chefirnemo"<<endl;
        else if(((n>1) && (m>1) && (n-2)%x==0) && ((m-2)%y==0))
            cout<<"Chefirnemo"<<endl;
        else
            cout<<"Pofik"<<endl;
    }
    return 0;
}