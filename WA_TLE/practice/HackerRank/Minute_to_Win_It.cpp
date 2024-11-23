// https://www.hackerrank.com/contests/w38/challenges/minute-to-win-it/problem
// Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int minuteToWinIt(vector<long> a, int k) {
    int n = a.size();
    int pos = 0, count = 0, max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == k)
            ++count;
        else
            count = 0;
        if (count > max) {
            pos = i;
            max = count;
        }
    }
    int time = 0;
    for (int i = pos - max; i > 0; i--) {
        if (a[i] - a[i - 1] != k) {
            a[i - 1] = a[i] - k;
            ++time;
        }
    }
    for (int i = pos; i < n - 1; i++) {
        if (a[i + 1] - a[i] != k) {
            a[i + 1] = a[i] + k;
            ++time;
        }
    }
    return time;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long> a(n);
    for (long &i : a) {
        cin >> i;
    }
    int result = minuteToWinIt(a, k);
    cout << result << endl;
}