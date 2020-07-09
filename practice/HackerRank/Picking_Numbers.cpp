// https://www.hackerrank.com/challenges/picking-numbers/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int pickingNumbers(vector <int> a) {
    // Complete this function
    int arr[101],i,max=0;
    for(i=0;i<101;i++)
        arr[i]=0;
    for(i=0;i<a.size();i++)
        ++arr[a[i]];
    for(i=0;i<100;i++)
        if(arr[i]+arr[i+1]>max)
            max=arr[i]+arr[i+1];
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = pickingNumbers(a);
    cout << result << endl;
    return 0;
}
