// https://www.codechef.com/SNCKQL19/problems/QUALPREL/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> s(n);
        for(int i=0;i<n;i++)
            cin>>s[i];
        sort(s.rbegin(),s.rend());
        int score_cut=s[k-1];
        while(score_cut == s[k] && k<n) {
            ++k;
        }
        cout<<k<<endl;
    }
}