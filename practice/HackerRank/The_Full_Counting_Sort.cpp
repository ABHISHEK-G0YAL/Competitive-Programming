// https://www.hackerrank.com/challenges/countingsort4/problem
// Accepted

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    string s;
    int n,x,N;
    cin>>n;
    N=n/2;
    vector<vector<string> > v(101);
    while(n--){
        cin>>x>>s;
        v[x].pb(n>=N?"-":s);
    }
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
}
