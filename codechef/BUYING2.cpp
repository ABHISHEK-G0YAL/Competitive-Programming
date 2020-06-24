#include <iostream>
using namespace std;

int main()
{
    int t,n,x,sum,min;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int notes[n];
        cin>>notes[0];
        sum=notes[0];
        min=notes[0];
        for(int i = 1; i < n; i++)
        {
            cin>>notes[i];
            sum+=notes[i];
            if(min>notes[i])
                min=notes[i];
        }
        if(sum/x == (sum-min)/x)
            cout<<"-1"<<endl;
        else
            cout<<sum/x<<endl;
    }
    return 0;
}