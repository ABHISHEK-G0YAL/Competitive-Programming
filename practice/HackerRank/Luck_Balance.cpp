// https://www.hackerrank.com/challenges/luck-balance/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    bool imp;
    vector<int> impContest;
    int luck, luckBalance = 0;
    for(int i = 0; i < n; i++) {
        cin >> luck >> imp;
        if(imp) impContest.push_back(luck);
        else luckBalance += luck;
    }
    sort(impContest.rbegin(), impContest.rend());
    for(int luck : impContest) {
        if(k-- > 0) luckBalance += luck;
        else luckBalance -= luck;
    }
    cout << luckBalance << endl;
}
