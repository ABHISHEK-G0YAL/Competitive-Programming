// https://www.codechef.com/problems/AMR15A

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,x,count=0;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        cin>>x;
        bool chk=x&1;
        if(!chk)
            ++count;
    }
    if(count>(n/2))
        cout<<"READY FOR BATTLE"<<endl;
    else
        cout<<"NOT READY"<<endl;
    return 0;
}