#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Assignment 1\n" << endl;
    cout << "Ouestion 4" << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    int x;
    cin >> x;
    cout << linearSearch(arr, x) << endl;
}