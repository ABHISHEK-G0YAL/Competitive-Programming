// http://codeforces.com/contest/1228/problem/B

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int mpow(int x) {
    if(x == 0) return 1;
    long long hans = mpow(x / 2);
    long long ans = (hans * hans) % mod;
    if(x % 2) return (2 * ans) % mod;
    else return ans;
}
bool grid[1005][1005];
void print(int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << grid[i][j] << " ";
        } cout << endl;
    }
}
int cnt(int R, int C) {
    int count = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            count += grid[i][j];
    return mpow(count);
}
int main() {
    memset(grid, 1, sizeof(grid));
    int R, C;
    cin >> R >> C;
    int r[R], c[C];
    for(int i = 0; i < R; i++) {
        cin >> r[i];
        memset(grid[i], 0, sizeof(bool) * r[i]);
    }
    for(int i = 0; i < C; i++) {
        cin >> c[i];
        for(int x = 0; x < c[i]; x++) {
            grid[x][i] = false;
        }
    }
    int count;
    for(int i = 0; i < R; i++) {
        count = 0;
        for(int j = 0; j < C; j++) {
            if(!grid[i][j])
                ++count;
            else break;
        }
        if(count != r[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < C; i++) {
        count = 0;
        for(int j = 0; j < R; j++) {
            if(!grid[j][i])
                ++count;
            else break;
        }
        if(count != c[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < R; i++) {
        if(r[i] != C)
            grid[i][r[i]] = false;
    }
    for(int i = 0; i < C; i++) {
        if(c[i] != R)
            grid[c[i]][i] = false;
    }
    cout << cnt(R, C) << endl;
}