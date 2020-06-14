#include <bits/stdc++.h>
using namespace std;

vector<string> DP[16][16];
void nSetBits() {
    int k = 15;
    string str = "";
    for (int i = 0; i <= k; i++) {
        DP[i][0].push_back(str);
        str = str + char(0);
    }
    // DP[k][n] will store all k-bit numbers
    // with n-bits set
    for (int i = 1; i <= k; i++) {
        for (int n = 1; n <= i; n++) {
            for (string str : DP[i - 1][n])
                DP[i][n].push_back(char(0) + str);
            for (string str : DP[i - 1][n - 1])
                DP[i][n].push_back(char(1) + str);
        }
    }
}
int sum(vector<int> v) {
    int sum = 0;
    for(auto i : v)
        sum += i;
    return sum;
}
void print_wall(vector<string> wall) {
    for(auto i : wall) {
        for(int j : i)
            cout << j << " ";
        cout << "\n";
    }
}
void paint(vector<string> &wall, vector<int> &row, vector<int> &col, int &cnt, vector<string> &fvp, int i = 0) {
    int n = row.size(), m = col.size();
    if(i == n) {
        if(sum(row) + sum(col) == 0) {
            ++cnt;
            if(cnt == 1)
                fvp = wall;
        } return;
    } int row_i = row[i];
    for(auto s : DP[m][row_i]) {
        row[i] = 0;
        wall[i] = s;
        vector<int> init_col(col);
        bool s_valid = true;
        for(int i = 0; i < col.size(); i++) {
            if(s[i]) {
                if(col[i] > 0)
                    col[i]--;
                else {
                    s_valid = false;
                    break;
                }
            }
        }
        if(s_valid)
            paint(wall, row, col, cnt, fvp, i + 1);
        col = init_col;
        row[i] = row_i;
    }
}
int main() {
    nSetBits();
    int n, m, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++)
            cin >> row[i];
        for(int i = 0; i < m; i++)
            cin >> col[i];
        vector<string> wall(n, string(m, 0));
        vector<string> first_valid_paint;
        int cnt_valid_paint = 0;
        paint(wall, row, col, cnt_valid_paint, first_valid_paint);
        if(cnt_valid_paint == 1)
            print_wall(first_valid_paint);
        else if(cnt_valid_paint == 0)
            cout << "No Possible Way\n";
        else
            cout << cnt_valid_paint << "\n";
    }
}