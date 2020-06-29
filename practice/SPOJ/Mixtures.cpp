// https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>
using namespace std;
int sum(int arr[],int s,int e) {
    int sm=0;
    for(int i=s;i<=e;i++)
        sm+=arr[i];
    return sm%100;
}
vector<vector<int>> mem;
int minCost(int arr[],int s,int e) {
    if(e<=s) return 0;
    if(mem[s][e]!=-1) return mem[s][e];
    int mCost = INT_MAX;
    for(int i=s;i<e;i++)
        mCost=min(mCost,minCost(arr,s,i)+minCost(arr,i+1,e)+(sum(arr,s,i)*sum(arr,i+1,e)));
    return mem[s][e]=mCost;
}
int main() {
    int n;
    while(cin>>n) {
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        mem = vector<vector<int>>(n,vector<int>(n,-1));
        cout<<minCost(arr,0,n-1)<<endl;
    }
}