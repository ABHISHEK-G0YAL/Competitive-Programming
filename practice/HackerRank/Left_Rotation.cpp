// https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cout<<a[(i+r)%n]<<" ";
    return 0;
}

