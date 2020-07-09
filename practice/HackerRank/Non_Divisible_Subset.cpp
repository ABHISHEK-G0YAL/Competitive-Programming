// https://www.hackerrank.com/challenges/non-divisible-subset/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n,k,x;
    cin>>n>>k;
    int s[k]={};
    for(int i=0;i<n;i++) {
        cin>>x;
        ++s[x%k];
    }
    int result=0;
    for(int i=0;i<=k/2;i++) {
        if(i==0 || i==k-i) result+=min(1,s[i]);
        else result+=max(s[i],s[k-i]);
    }
    fout << result << "\n";
    fout.close();
    return 0;
}
