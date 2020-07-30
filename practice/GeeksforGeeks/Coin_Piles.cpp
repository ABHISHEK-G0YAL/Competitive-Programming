// https://practice.geeksforgeeks.org/problems/coin-piles/0/

// O(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, x, sum, pile_cnt, pile_min[1005], pile_rem[1005];
    cin >> t;
    while(t--) {
        cin >> n >> k;
        sum = 0;
        memset(pile_min, 0, sizeof(pile_min));
        memset(pile_rem, 0, sizeof(pile_rem));
        for(int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            ++pile_rem[x];
        }
        pile_cnt = 0;
        for(int i = 1; i < 1005; i++) {
            pile_min[i] = n - pile_cnt;
            pile_cnt += pile_rem[i];
            pile_rem[i] *= i;
            pile_min[i] += pile_min[i - 1];
            pile_rem[i] += pile_rem[i - 1];
        }
        int min_c = INT_MAX;
        for(int i = 1; i + k < 1005; i++)
            min_c = min(min_c, sum - (pile_min[i + k] - pile_rem[i - 1]));
        cout << min_c << endl;
    }
	return 0;
}