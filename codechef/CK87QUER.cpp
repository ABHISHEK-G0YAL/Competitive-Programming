#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    long long t,y,count;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>y;
        for(int b=1;b<=700;b++)
            if(b<y)
                count+=sqrt(y-b);        //count+=a;
        cout<<count<<endl;
    }
    return 0;
}