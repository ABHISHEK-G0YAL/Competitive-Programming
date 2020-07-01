// https://www.codechef.com/UCSD2020/problems/DSLA3

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void print(vvi &a) {
    for(auto &v : a)
        for(int &i : v)
            cout << i << " ";
    cout << endl;
}
int twodplay(vvi &v) {
    int n = v.size(), sc = 0;
    for(int i = 0; i < n; i += 1) {
        for(int j = 0; j < n; j += 1) {
            int mi = i;
            for(int r = i + 1; r < n; r += 1)
                mi = v[r][j] < v[mi][j] ? r : mi;
            swap(v[i][j], v[mi][j]);
            sc += (i != mi);
        }
        for(int j = 0; j < n; j += 1) {
            int mi = i;
            for(int c = i + 1; c < n; c += 1)
                mi = v[j][c] < v[j][mi] ? c : mi;
            swap(v[j][i], v[j][mi]);
            sc += (i != mi);
        }
    }
    return sc;
}
int main() {
    int n; cin >> n;
    vvi a(n, vi(n));
    for(auto &r : a) for(int &i : r) cin >> i;
    cout << twodplay(a) << endl;
    print(a);
}