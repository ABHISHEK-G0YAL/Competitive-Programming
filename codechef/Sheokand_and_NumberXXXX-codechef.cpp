#include <iostream>
#include <unordered_map>
#define ui unsigned int
using namespace std;


int main()
{
    const ui one=1;
    unordered_map <ui,pair<ui,ui> > graph;
    for(int x=0;x<=30;x++)
        for(int y=x+1;y<=30;y++)
            graph[(one<<x) + (one<<y)]=make_pair(x,y);
    ui t;
    cin>>t;
    while(t--)
    {
        int n,low,up;
        cin>>n;
        for(int i=n;;i--)
        {
            auto it=graph.find(i);
            if(it!=graph.end())
                low=i;
            else
                continue;
            break;
        }
        for(int i=n;;i++)
        {
            auto it=graph.find(i);
            if(it!=graph.end())
                up=i;
            else
                continue;
            break;
        }
        cout<<min(up-n,n-low)<<endl;
    }
    return 0;
}
