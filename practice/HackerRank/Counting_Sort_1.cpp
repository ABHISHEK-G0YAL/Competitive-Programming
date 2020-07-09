// https://www.hackerrank.com/challenges/countingsort1/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x; cin>>n;
    int arr[100] = {};
    for(int i=0;i<n;i++) {
        cin>>x;
        arr[x]++;
    } for(int i=0;i<100;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
