// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> scores(1),alice;
    int n,m,x;
    cin>>n;
    cin>>scores[0];
    for(int i=1;i<n;i++)
    {
        cin>>x;
        if(x!=scores.back())
           scores.push_back(x);
    }
    scores.push_back(0);
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        alice.push_back(x);
    }
    int i=scores.size()-1,j;
    for(j=0;j<m;j++)
    {
        for(;i>=0;i--)
            if(scores[i]>alice[j])
                break;
        cout<<i+2<<endl;
    }
}
