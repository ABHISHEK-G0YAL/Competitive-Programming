// https://www.hackerrank.com/challenges/plus-minus/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

void plusMinus(vector <int> arr) {
    // Complete this function
    int p[3]={0,0,0};
    for(int i=0 ;i<arr.size();i++)
    {
        if(arr[i]>0)
            ++p[0];
        else if(arr[i]<0)
            ++p[1];
        else
            ++p[2];
    }
    for(int i=0;i<3;i++)
    {
        float f=float(p[i])/float(arr.size());
        cout << f <<'\n';
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    plusMinus(arr);
    return 0;
}
