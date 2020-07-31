# Modified sum

Ninja recently learned the maximum sum subarray algorithm in his dynamic programming lecture at Coding Ninjas and he is bragging about this in front of his friends. So one of his friends thought of checking his skills by giving him a little modified version of Maximum sum subarray problem.

The modification is that Ninja is allowed to choose a subarray and multiply its every entry by a given number X before finding the maximum sum subarray, but this operation can only be done at most one time.

Formally, you are given an array of length N and integer X, and you can choose a subarray and multiply it with X at most one time, and after this, you need to output the sum of the maximum sum subarray.

This problem turned out to be a little bit difficult for Ninja, and he is asking for your help.

Note: A subarray is a continuous segment of an array.

### Input format
    First line will contain T ( number of test cases).
    Every test case will consist of two lines the first line will contain two integers N and X, that denote the number of elements in array and number you can multiply to chosen subarray, respectively.
    The next line of input will contain N space-separated integers (the elements of the array).

### Constraints
    1<=T<=10^5
    1<=N<=10^5
    -500<=X<=500
    -10^9<=A[i]<=10^9 for each i in [1,n]
    Sum of N over all testcases doesn’t exceed 5*10^5

### Output format
    For every test case, print the sum of the maximum sum subarray in a newline.

### Sample Input 1:
    3
    5 9
    1 2 3 4 5
    4 0
    -1 -2 -3 892
    5 -1
    -10 -10 -10 10 10

### Sample Output 1:
    135
    892
    50

### Explanation
    In test case 1: we will multiple the complete sum array to get { 9, 18, 27, 36, 45}, and since all are positive the maximum sum that we can get is 135 ( 9+18+27+36+45).
    In test case 2: No need to multiply any subarray.
    In test case 3: We will choose the subarray {-10,-10,-10}.

# Solution
```cpp
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class solution {
    ll dp[100005][3];
    ll solve(vector<ll> &a, ll idx, ll x, ll cur=0) {
        int n = a.size();
        if (idx == n)
            return 0;
        if (dp[idx][cur] != -1)
            return dp[idx][cur];
        ll ans = 0;
        if (cur == 0) {
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 0));
            ans = max(ans, x * a[idx] + solve(a, idx + 1, x, 1));
        }
        else if (cur == 1) {
            ans = max(ans, x * a[idx] + solve(a, idx + 1, x, 1));
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 2));
        }
        else
            ans = max(ans, a[idx] + solve(a, idx + 1, x, 2));
        return dp[idx][cur] = ans;
    }
public:
    ll getSum(vector<ll> &a, ll x) {
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        ll sum = 0;
        for (ll i = 0; i < n; i++)
            sum = max(sum, solve(a, i, x));
        return sum;
    }
};

int main() {
    solution s;
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for(ll &i : a)
            cin >> i;
        cout << s.getSum(a, x) << endl;
    }
}
```