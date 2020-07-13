// https://www.hackerrank.com/challenges/closest-numbers/problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> a(n,INT_MAX);
    vector<int> b;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int min=INT_MAX;
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
    for(int i=1;i<n;i++) {
        if(abs(a[i]-a[i-1])==min) {
            b.push_back(a[i-1]);
            b.push_back(a[i]);
            // cout<<a[i-1]<<" "<<a[i]<<endl;
        } else if(abs(a[i]-a[i-1])<min) {
            min=abs(a[i]-a[i-1]);
            b.clear();
            b.push_back(a[i-1]);
            b.push_back(a[i]);
            // cout<<"clear"<<endl;
            // cout<<a[i-1]<<" "<<a[i]<<endl;
        }
    } for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
