// https://www.hackerrank.com/challenges/angry-children/problem

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> &arr) {
    int unfairness = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i = 0; i + k - 1 < arr.size(); i += 1)
        unfairness = min(unfairness, arr[i + k - 1] - arr[i]);
    return unfairness;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << maxMin(k, arr) << endl;
}
