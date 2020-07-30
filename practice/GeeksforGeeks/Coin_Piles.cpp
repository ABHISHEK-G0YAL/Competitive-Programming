// https://practice.geeksforgeeks.org/problems/coin-piles/0/

// O(n^2)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> v(n);
        for(auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int n_sum = 0, r_sum, max_pile, min_c = INT_MAX, i = 0;
        while(i < n) {
            r_sum = 0;
            max_pile = v[i] + k;
            for(int j = i; j < n; j++) {
                if(v[j] - max_pile > 0)
                    r_sum += v[j] - max_pile;
            }
            min_c = min(min_c, n_sum + r_sum);
            while(i + 1 < n and v[i] == v[i + 1]) {
                n_sum += v[i];
                i += 1;
            }
            n_sum += v[i];
            i += 1;
        }
        cout << min_c << endl;
    }
	return 0;
}