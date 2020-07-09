// https://www.hackerrank.com/challenges/beautiful-pairs/problem
// Accepted

#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int main() {
    int n,x,a[MAX]={0},b[MAX]={0},count=0; cin>>n;
    for(int i=0;i<n;i++){ cin>>x; a[x]++; }
    for(int i=0;i<n;i++){ cin>>x; b[x]++; }
    for(int i=0;i<MAX;i++) count+=min(a[i],b[i]);
    cout<<count+(count==n?-1:1)<<endl;
}