#include <bits/stdc++.h>
using namespace std;
#define SWAP(a,b) {char temp; temp=a; a=b; b=temp;}

int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int d,charge,power,swapcount=0;string p;
        cin>>d>>p;
        int plength=p.length();
        recheck:charge=1;power=0;
        for(int i=0;i<plength;i++)
        {
            if(p[i]=='S')
            power+=charge;
            else
            charge*=2;
        }
        if(power<=d)
        {
            cout<<"Case #"<<x<<": "<<swapcount<<endl;
            continue;
        }
        else
        {
            for(int j=plength-1;j>0;j--)
            {
                if(p[j]=='S' && p[j-1]=='C')
                {
                    SWAP(p[j],p[j-1])
                    ++swapcount;
                    goto recheck;
                }
            }
        }
        cout<<"Case #"<<x<<": IMPOSSIBLE"<<endl;
    }
    return 0;
}
