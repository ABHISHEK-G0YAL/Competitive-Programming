// https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,nq,q;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i]; 
    cin>>nq;
    for(int i=0;i<nq;i++) {
        cin>>q;
        vector<int>::iterator it;
        it=lower_bound(v.begin(),v.end(),q);
        if(*it==q) cout<<"Yes "<<it-v.begin()+1<<endl;
        else cout<<"No "<<it-v.begin()+1<<endl;
    }
    return 0;
}
