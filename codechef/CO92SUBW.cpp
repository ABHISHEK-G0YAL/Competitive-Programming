// https://www.codechef.com/problems/CO92SUBW

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,i,x,s1,s2;
    cin>>t;
    while(t--)
    {
        s1=0;
        cin>>x;
        for(i=1;;i++)
        {
            s1=s1+i;
            if(s1>=x)
                break;
        }
        s2=s1-i;
        if(s1==x)
            cout<<i<<endl;
        else if((s1-x)<(x-s2))
            cout<<i+s1-x<<endl;
        else
            cout<<i-1+x-s2<<endl;
    }
    return 0;
}