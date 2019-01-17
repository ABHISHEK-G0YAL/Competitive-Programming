#include <bits/stdc++.h>
#define ui unsigned int
using namespace std;
 
 
int main()
{
    const ui one=1;
    vector<ui> graph;
    for(int x=0;x<=30;x++)
        for(int y=x+1;y<=30;y++)
            graph.push_back((one<<x)+(one<<y));
    sort(graph.begin(),graph.end());
    ui t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int low=n+1,up=n-1;
        while(!binary_search(graph.begin(),graph.end(),--low)){}
        while(!binary_search(graph.begin(),graph.end(),++up)){}
        cout<<min(up-n,n-low)<<endl;
    }
    return 0;
}