// https://www.codechef.com/COOK103A/problems/MAXREMOV

#include <bits/stdc++.h>
#define MAX 100002
using namespace std;

int cake[MAX], psum_k[MAX], psum_k1[MAX];

int main() {
    int t, n, k, max_ck;
    cin >> t;
    while(t--) {
        memset(cake, 0, sizeof(cake));
        memset(psum_k, 0, sizeof(psum_k));
        memset(psum_k1, 0, sizeof(psum_k1));
        cin >> n >> k;
        vector<pair<int, int> > v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            cake[v[i].first] += 1;
            cake[v[i].second + 1] -= 1;
        }
        for(int i = 1; i < MAX; i++) {
            cake[i] += cake[i - 1];
            psum_k[i] = (cake[i] == k) + psum_k[i - 1];
            psum_k1[i] = (cake[i] == k + 1) + psum_k1[i - 1];
        }
        max_ck = 0;
        for(auto &p : v)
            max_ck = max(max_ck, psum_k[p.first - 1] + (psum_k1[p.second] - psum_k1[p.first - 1]) + (psum_k[MAX - 1] - psum_k[p.second]));
        cout << max_ck << endl;
    }
}