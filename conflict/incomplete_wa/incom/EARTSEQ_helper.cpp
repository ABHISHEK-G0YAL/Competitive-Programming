#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n; cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"gcd of every two cyclically consecutive numbers"<<endl;
        for(int i=0;i<n;i++)
            cout<<__gcd(arr[i],arr[(i+1)%n])<<" ";
        cout<<endl<<"gcd of every three cyclically consecutive numbers"<<endl;
        for(int i=0;i<n;i++)
            cout<<__gcd(__gcd(arr[i],arr[(i+1)%n]),arr[(i+2)%n])<<" ";
        cout<<endl;
    }
}