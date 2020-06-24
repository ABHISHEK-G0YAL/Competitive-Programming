// https://www.codechef.com/problems/CHEFRUN

#include <iostream>
using namespace std;

int main()
{
    double t,x1,x2,x3,v1,v2;
    double t1,t2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>x2>>x3>>v1>>v2;
        t1=(x3-x1)/v1;
        t2=(x2-x3)/v2;
        if(t1<t2)
        cout<<"Chef"<<endl;
        else if(t2<t1)
        cout<<"Kefa"<<endl;
        else
        cout<<"Draw"<<endl;
    }
}