// https://www.hackerrank.com/challenges/icecream-parlor/problem

#include <bits/stdc++.h>
#define mx 10005
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, c;
        cin >> m >> n;
        vector<queue<int>> cost(mx);
        for (int i = 0; i < n; i++) {
            cin >> c;
            cost[c].push(i + 1);
        }
        for (int c = 1; c < m; c++) {
            if(cost[c].empty()) continue;
            int i = cost[c].front();
            cost[c].pop();
            if(cost[m - c].size() > 0) {
                int j = cost[m - c].front();
                cost[m - c].pop();
                cout << min(i, j) << " " << max(i, j) << endl;
                break;
            }
        }
    } return 0;
}
