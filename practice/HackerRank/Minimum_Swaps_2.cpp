// https://www.hackerrank.com/challenges/minimum-swaps-2/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> &a) {
    int minSwaps = 0, swaps = 1000;
    while (swaps) {
        swaps = 0;
        for(int i = 0; i < a.size(); i += 1) {
            if(a[i] != i + 1) {
                swap(a[i], a[a[i] - 1]);
                swaps += 1;
            }
        }
        minSwaps += swaps;
    }
    return minSwaps;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    cout << minimumSwaps(a);
}
