// https://www.hackerrank.com/challenges/unbounded-knapsack/problem

#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

int dp[MAX];
int unboundedKnapsack(int k, vector<int> arr) {
    for(int i=0;i<=k;i++)
        for(int j=0;j<arr.size();j++)
            if(arr[j]<=i)
                if(arr[j]+dp[i-arr[j]] > dp[i])
                    dp[i]=arr[j]+dp[i-arr[j]];
    return dp[k];
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int t,n,k;
    cin >> t;
    while(t--) {
        memset(dp,0,sizeof(dp));
        cin>>n>>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin>>arr[i];
        int result = unboundedKnapsack(k, arr);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
