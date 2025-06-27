// https://www.hackerrank.com/challenges/frequency-queries/problem

#include <bits/stdc++.h>
using namespace std;

vector<int> freqQuery(vector<vector<int>> queries) {
    unordered_map<int, int> freq; // frequency
    unordered_map<int, int> hof; // higherOrderFrequency
    
    vector<int> ans;
    for (auto q : queries) {
        int type = q[0], x = q[1];

        if (type == 1) {
            --hof[freq[x]];
            ++freq[x];
            ++hof[freq[x]];
        } else if (type == 2) {
            if (freq[x] > 0) {
                --hof[freq[x]];
                --freq[x];
                ++hof[freq[x]];
            }
        } else {
            ans.push_back(hof[x] >= 1);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> queries(n);
    for (int i = 0; i < n; i++) {
        queries[i].resize(2);
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = freqQuery(queries);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
