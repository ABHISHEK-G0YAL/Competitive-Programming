// https://www.codechef.com/JULY19A/problems/CCC/
// Partially Solved (10pts)

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<ll> v) {
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n, z;
        cin >> n >> z;
        vector<ll> hits(n);
        ll min_hits = 0;
        for(int i = 0; i < n; i++)
            cin >> hits[i];
        for(int i = 0; i < z; i++) {
            sort(hits.begin(), hits.end());
            // print(hits);
            vector<ll> temp(hits);
            for(int i = 0; i < n; i++)
                temp[i] *= (n - i);
            // print(temp);
            auto min_itr = min_element(temp.begin() + i, temp.end());
            ll min_index = min_itr - temp.begin();
            ll hit_coco = hits[min_index];
            // cout << min_index << endl;
            for(int i = min_index; i < n; i++)
                hits[i] -= hit_coco;
            min_hits += *min_itr;
        } cout << min_hits << endl;
    }
}