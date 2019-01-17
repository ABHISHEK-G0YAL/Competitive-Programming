#include <iostream>
#include <unordered_map>
// #include <pair>
#define ui unsigned int
using namespace std;


int main()
{
    const ui one=1;
    unordered_map <ui,pair<ui,ui> > graph;
    for(int x=0;x<=30;x++)
        for(int y=x+1;y<=30;y++)
            graph[(one<<x) + (one<<y)]=make_pair(x,y);
    // cout<<graph.at(4).first<<endl;
    // cout<<graph.at(4).second<<endl;
    ui t;
    cin>>t;
    while(t--)
    {
        int n,low,up;
        cin>>n;
        for(int i=n;;i--)
        {
            try
            {
                graph.at(i);
                low=i;
                break;
            }
            catch(...) {}
        }
        for(int i=n;;i++)
        {
            try
            {
                graph.at(i);
                up=i;
                break;
            }
            catch(...) {}
        }
        cout<<min(up-n,n-low)<<endl;
    }
    return 0;
}
