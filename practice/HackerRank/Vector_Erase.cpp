// https://www.hackerrank.com/challenges/vector-erase/problem
// Accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    } int ind; pair<int,int> range;
    cin>>ind;
    cin>>range.first>>range.second;
    a.erase(a.begin()+ind-1);
    a.erase(a.begin()+range.first-1,a.begin()+range.second-1);
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";
    } cout<<endl;
    return 0;
}
