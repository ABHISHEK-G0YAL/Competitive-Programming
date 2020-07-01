// https://www.codechef.com/SATA2019/problems/SAT102

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int>(m));
        for(auto &v : grid)
            for(auto &i : v)
                cin >> i;
        int prev = 0;
        for(auto &i : grid[0]) {
            i += prev;
            prev = i;
        }
        prev = 0;
        for(auto &v : grid) {
            v[0] += prev;
            prev = v[0];
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                grid[i][j] += max({grid[i - 1][j], grid[i][j - 1], grid[i - 1][j - 1]});
        cout << grid[n - 1][m - 1] << endl;
    }
}