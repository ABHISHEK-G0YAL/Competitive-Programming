// https://www.codechef.com/UCDS2020/problems/MIDLE002/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, n;
    cin >> p >> q >> n;
    vector<vector<int> > mat(p, vector<int>(q, 0));
    int i, j, x;
    while(n--) {
        cin >> i >> j >> x;
        mat[i][j] = x;
    }
    cin >> i >> j;
    // dirs = {null, down, right, up, left};
    int dir[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}}, pd = 1; x = 0;
    for(;;) {
        for(int d = 1; d <= 4; d++) {
            x += d % 2;
            int m = x;
            while(m--) {
                if(i >= p or j >= q or i < 0 or j < 0)
                    goto exit;
                if(mat[i][j] != 0)
                    cout << i << " " << j << " " << mat[i][j] << " " << pd << endl;
                i += dir[d][0];
                j += dir[d][1];
                pd = d;
            }
        }
    }
    exit: return 0;
}