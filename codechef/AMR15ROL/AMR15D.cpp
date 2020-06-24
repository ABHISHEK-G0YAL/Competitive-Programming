// https://www.codechef.com/problems/AMR15D

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cin>>q;
    while(q--) {
        int x,sum=0;
        cin>>x;
        int count=ceil(n/float(x+1));
        for(int i=0;i<count;i++)
            sum+=arr[i];
        cout<<sum<<endl;
    }
    return 0;
}