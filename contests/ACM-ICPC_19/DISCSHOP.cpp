// https://www.codechef.com/ICPCIN19/problems/DISCSHOP

#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        int mn = INT_MAX;
        vector<int> a(s.length(), 0);
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < s.length(); j++)
                if(i != j)
                    a[i] = (a[i] * 10) + (s[j] - '0');
            mn = min(mn, a[i]);
        }
        cout << mn << endl;
    }
    return 0;
}