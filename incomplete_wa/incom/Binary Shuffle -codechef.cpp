#include <iostream>
#define ull unsigned long long
using namespace std;

int main()
{
    int t,i,j,count,ba,bb;
    ull a,b;
    cin>>t;
    
    while(t--)
    {
        cin>>a>>b;
        if(a<=b)
        {
            count=0;
            for(i=63;i>=0;i--)
            {
                if((a & 1ULL<<i) ^ (b & 1ULL<<i))
                {
                    ba=i;
                    bb=-1;
                    i--;
                    for(;i>=0;i--)
                        if(((a & 1ULL<<i) ^ (b & 1ULL<<i)) && ((a & 1ULL<<i) ^ (a & 1ULL<<ba)))
                            bb=i;
                    if((bb!=-1) && (((a^(1ULL<<ba))^(1ULL<<bb))+1 <= b))
                        a=((a^(1ULL<<ba))^(1ULL<<bb))+1;
                    else
                        a+=1;
                    ++count;
                    i=63;
                }
            }
            cout<<count<<endl;
        }
        //else
    }
    return 0;
}
