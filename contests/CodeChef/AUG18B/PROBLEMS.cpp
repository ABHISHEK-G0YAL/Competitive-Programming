// https://www.codechef.com/AUG18B/problems/PROBLEMS

#include <bits/stdc++.h>
#define ui unsigned  int
using namespace std;

int main()
{
    ui p,s;
    cin>>p>>s;
    vector<pair<ui,ui >> order;
    for(ui x=1;x<=p;x++)
    {
        int c=0;
        vector<ui> sc(s);
        map<ui,ui> scns;
        for(ui i=0;i<s;i++)
            cin>>sc[i];
        for(ui i=0;i<s;i++)
            cin>>scns[sc[i]];
        auto itr=scns.begin();
        auto itr_end=--scns.end();
        while(itr != itr_end)
            if(itr->second > (++itr)->second)
                ++c;
        order.push_back(make_pair(c,x));
    }
    sort(order.begin(),order.end());
    for(ui x=0;x<p;x++)
        cout<<order[x].second<<endl;
    return 0;
}