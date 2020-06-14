#include <bits/stdc++.h>
using namespace std;

int sumof(vector<int> arr) {
    int sum = 0;
    for(int i : arr)
        sum += i;
    return sum;
}

int maxof(vector<int> arr) {
    int max = INT_MIN;
    for(int i : arr)
        if(i > max)
            max = i;
    return max;
}

int main() {
    cout << "Assignment 1" << endl;
    cout << "Ouestion 1" << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    cout << sumof(arr) << endl;
    cout << maxof(arr) << endl;
    int x;
    cin >> x;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == x) {
            cout << x << " found at index " << i << endl;
            i = -1;
            break;
        }
    }
    if(i != -1)
        cout << x << " not found" << endl;
}