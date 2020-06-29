#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int arr[n],min_i;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++) {
        min_i=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min_i])
                min_i=j;            
        }
        swap(arr[i],arr[min_i]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}