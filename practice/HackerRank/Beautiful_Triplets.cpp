// https://www.hackerrank.com/challenges/beautiful-triplets/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int beautifulTriplets(int d, vector <int> arr) {
    // Complete this function
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]-arr[i]!=d)
                continue;
            for(int k=j+1;k<arr.size();k++)
                if(arr[k]-arr[j]==d)
                    ++count;
        }
    }
    return count;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = beautifulTriplets(d, arr);
    cout << result << endl;
    return 0;
}
