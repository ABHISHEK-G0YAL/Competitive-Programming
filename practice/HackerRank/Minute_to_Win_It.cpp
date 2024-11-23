// https://www.hackerrank.com/contests/w38/challenges/minute-to-win-it/problem

#include <bits/stdc++.h>
using namespace std;

int minuteToWinIt(vector<long> a, long k) {
    // a`[i] = C + i * k;
    unordered_map<long, int> f_mp;
    int max_correct = 0;
    for (int i = 0; i < a.size(); i++) {
        long C = a[i] - i * k;
        ++f_mp[C];
        max_correct = max(max_correct, f_mp[C]);
    }
    return a.size() - max_correct;
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