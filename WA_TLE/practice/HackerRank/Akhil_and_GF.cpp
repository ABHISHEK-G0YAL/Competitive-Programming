// https://www.hackerrank.com/challenges/akhil-and-gf/problem
// Wrong Answer

#include <bits/stdc++.h>
using namespace std;

// Complete the solve function below.
int solve(long n, int m) {
    int num = 1;
    vector<int> initial, loop;
    for (int i = 0; i <= log10(m); i++) {
        initial.push_back(num);
        // cout << "i" << num << " ";
        num = (num * 10 + 1) % m;
    }
    loop.push_back(num);
    // cout << "l" << num << " ";
    num = (num * 10 + 1) % m;
    while (num != loop[0]) {
        loop.push_back(num);
        // cout << "l" << num << " ";
        num = (num * 10 + 1) % m;
    }
    // cout << endl;
    if (n <= initial.size())
        return initial[n - 1];
    else
        return loop[(n - initial.size() - 1) % loop.size()];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long n;
        int m;
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}