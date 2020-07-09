// https://www.hackerrank.com/challenges/mini-max-sum/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <long long> arr) {
    // Complete this function
    long long sum=0,min=arr[0],max=arr[0];
    for(long long i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
        sum=sum+arr[i];
    }
    cout<<sum-max<<' '<<sum-min;
}

int main() {
    vector<long long> arr(5);
    for(long long arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMaxSum(arr);
    return 0;
}
