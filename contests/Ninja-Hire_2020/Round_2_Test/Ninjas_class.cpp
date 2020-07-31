// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/contests/Ninja-Hire_2020/Round_2_Test/Ninjas_class.md

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int t, i, j, n;
    ll arr[100005], mon[100005];
    cin >> t;
    while(t--) {
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        memset(mon, 0, sizeof(mon));
        for(i = 1; i <= n; i++) {
            j = i;
            while(j <= n) {
                mon[j] += arr[i];
                j += i;
            }
            cout << mon[i] << " ";
        }
        cout << endl;
    }
    return 0;
}