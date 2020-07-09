// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar)
{
    // Complete this function
    int count[k],pairs=0;
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i =0;i<n;i++)
        ++count[ar[i]%k];
    pairs+=count[0]*(count[0]-1)/2;
    for(int i=1;i<=k/2 && i!=k-i;i++)
        pairs+=count[i]*count[k-i];
    if(k%2==0)
        pairs+=count[k/2]*(count[k/2]-1)/2;
    return pairs;
}
int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}
