// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);
    for (auto &q : queries) {
        int a = q[0], b = q[1], k = q[2];
        arr[a - 1] += k;
        arr[b] -= k;
    }
    long maxN = arr[0];
    for (int i = 1; i < n; i += 1) {
        arr[i] += arr[i - 1];
        maxN = max(maxN, arr[i]);
    }
    return maxN;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > queries(m, vector<int>(3));
    for (auto &q : queries)
        cin >> q[0] >> q[1] >> q[2];
    cout << arrayManipulation(n, queries) << endl;
    return 0;
}
