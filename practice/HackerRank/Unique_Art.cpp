// https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem

#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

int BLOCK_SIZE;

bool cmpQuery(const Query &a, const Query &b) {
    int blockA = a.l / BLOCK_SIZE;
    int blockB = b.l / BLOCK_SIZE;
    if(blockA == blockB)
        return a.r < b.r;
    return blockA < blockB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Coordinate compression: compress values to [0, M-1]
    vector<int> vals = arr;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < n; i++){
        arr[i] = lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin();
    }
    int m = vals.size();  // number of distinct painting values
    
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        // Convert from 1-indexed to 0-indexed.
        queries[i] = {l - 1, r - 1, i};
    }
    
    // Determine block size (approximately sqrt(n))
    BLOCK_SIZE = static_cast<int>(sqrt(n));
    
    sort(queries.begin(), queries.end(), cmpQuery);
    
    // Frequency array for painting values (after compression)
    vector<int> freq(m, 0);
    int currL = 0, currR = -1, currAns = 0;
    vector<int> ans(q, 0);
    
    auto add = [&](int idx) {
        int val = arr[idx];
        freq[val]++;
        if(freq[val] == 1) {
            // Newly added unique element
            currAns++;
        } else if(freq[val] == 2) {
            // It was unique and now appears twice
            currAns--;
        }
    };
    
    auto remove = [&](int idx) {
        int val = arr[idx];
        freq[val]--;
        if(freq[val] == 1) {
            // After removal, becomes unique
            currAns++;
        } else if(freq[val] == 0) {
            // Element removed completely from window
            currAns--;
        }
    };
    
    // Process queries in Mo's order.
    for (auto &query : queries) {
        int L = query.l, R = query.r;
        
        // Expand the current range [currL, currR] to [L, R]
        while (currR < R) {
            currR++;
            add(currR);
        }
        while (currR > R) {
            remove(currR);
            currR--;
        }
        while (currL < L) {
            remove(currL);
            currL++;
        }
        while (currL > L) {
            currL--;
            add(currL);
        }
        
        ans[query.idx] = currAns;
    }
    
    for (int res : ans) {
        cout << res << "\n";
    }
    
    return 0;
}