// https://www.hackerrank.com/challenges/between-two-sets/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;
int max(int ar[],int size) {
    int max=ar[0];
    for(int i=1;i<size;i++)
        if(ar[i]>max) max=ar[i];
    return max;
}
int min(int ar[],int size) {
    int min=ar[0];
    for(int i=1;i<size;i++)
        if(ar[i]<min) min=ar[i];
    return min;
}
bool condition1(int ar[],int size,int x) {
    for(int i=0;i<size;i++)
        if(x%ar[i] != 0) return false;
    return true;
}
bool condition2(int ar[],int size,int x) {
    for(int i=0;i<size;i++)
        if(ar[i]%x != 0) return false;
    return true;
}
int main() {
    int m,n;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    int max_a=max(a,n);
    int min_b=min(b,m);
    int count=0;
    for(int i=max_a;i<=min_b;i++) {
        if(condition1(a,n,i) && condition2(b,m,i))
            ++count;
    } cout<<count<<endl;
    return 0;
}
