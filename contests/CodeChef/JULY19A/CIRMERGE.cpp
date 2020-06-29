// https://www.codechef.com/JULY19A/problems/CIRMERGE/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[805][805];

ll minPenalty(ll arr[], int s, int e) {
    if(s == e) return 0;
    if(dp[s][e] == 0) {
        ll  ans, arr_sum = 0, min_ans = INT64_MAX;
        for(int i = s; i <= e; i++)
            arr_sum += arr[i];
        for(int i = s; i < e; i++) {
            ans = minPenalty(arr, s, i) + minPenalty(arr, i + 1, e) + arr_sum;
            min_ans = min(ans, min_ans);
        } dp[s][e] = min_ans;
    } return dp[s][e];
}
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        ll arr[2 * n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[n + i] = arr[i];
        } memset(dp, 0, sizeof(dp));
        ll ans, min_ans = INT64_MAX;
        for(int i = 0; i < n; i++) {
            ans = minPenalty(arr, i, n + i - 1);
            min_ans = min(ans, min_ans);
        } cout << min_ans << endl;
    } return 0;
}