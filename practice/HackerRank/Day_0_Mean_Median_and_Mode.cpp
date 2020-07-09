// https://www.hackerrank.com/challenges/s10-basic-statistics/problem
// Accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,freq=1,max=0;
    float mean=0,median,mode;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        mean+=arr[i]/n;
    median=(arr[n/2]+arr[(n-1)/2])/2;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
            ++freq;
        else
            freq=1;
        if(freq>max)
        {
            max=freq;
            mode=arr[i];
        }
    }
    cout<<mean<<endl;
    cout<<median<<endl;
    cout<<mode<<endl;
    return 0;
}
