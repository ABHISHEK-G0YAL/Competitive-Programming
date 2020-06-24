// https://www.codechef.com/ICPCIN19/problems/TRAINSET

#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main() {
    int t, n;
    string s;
    bool first;
    cin >> t;
    while(t--) {
        cin >> n;
        unordered_map<string, pair<int, int> > mp;
        while(n--) {
            cin >> s >> first;
            if(first)
                mp[s].first += 1;
            else
                mp[s].second += 1;
        }
        int sum = 0;
        for(auto p : mp) {
            sum += max(p.second.first, p.second.second);
        }
        cout << sum << endl;
    }
    return 0;
}