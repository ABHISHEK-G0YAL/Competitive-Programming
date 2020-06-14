#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> v) {
    int sum = 0;
    for(auto i : v)
        sum += i;
    return sum;
}
void print_wall(vector<string> wall) {
    for(auto i : wall) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
void paint(vector<string> &wall, vector<int> &row, vector<int> &col, int &cnt, vector<string> &fvp, int block = 0) {
    int n = wall.size(), m = wall[0].size();
    int i = block / m, j = block % m;
    if(sum(row) + sum(col) == 0) {
        ++cnt;
        if(cnt == 1)
            fvp = wall;
        return;
    } if(block == n * m) return;
    paint(wall, row, col, cnt, fvp, block + 1);
    if(row[i] > 0 && col[j] > 0) {
        wall[i][j] = '1';
        row[i]--;
        col[j]--;
        paint(wall, row, col, cnt, fvp, block + 1);
        wall[i][j] = '0';
        row[i]++;
        col[j]++;
    }
}
int main() {
    int n, m, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++)
            cin >> row[i];
        for(int i = 0; i < m; i++)
            cin >> col[i];
        vector<string> wall(n, string(m, '0'));
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