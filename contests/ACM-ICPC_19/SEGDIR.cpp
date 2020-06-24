// https://www.codechef.com/ICPCIN19/problems/SEGDIR
// Wrong Answer

#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool isInter(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first >= p2.first and p1.first <= p2.second)
        return true;
    if(p2.first >= p1.first and p2.first <= p1.second)
        return true;
    return false;
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}
int main() {
    int t, n, l , r, v;
    cin >> t;
    while(t--) {
        bool gAns = false;
        cin >> n;
        unordered_map<int, vector<pair<pair<int, int>, bool> > > mp;
        while(n--) {
            cin >> l >> r >> v;
            mp[v].push_back({{l, r}, true});
        }
        for(auto iv : mp) {
            for(int i = 0; i < iv.second.size(); i++) {
                if(iv.second[i].second) {
                    for(int j = i + 1; j < iv.second.size(); j++) {
                        if(iv.second[j].second) {
                            if(isInter(iv.second[i].first, iv.second[j].first)) {
                                iv.second[j].second = false;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < iv.second.size(); i++) {
                if(!iv.second[i].second) {
                    for(int j = i + 1; j < iv.second.size(); j++) {
                        if(!iv.second[j].second) {
                            if(isInter(iv.second[i].first, iv.second[j].first)) {
                                cout << "NO" << endl;
                                gAns = true;
                                break;
                            }
                        }
                    }
                    if(gAns)
                        break;
                }
            }
            if(gAns)
                break;
        }
        if(gAns)
            continue;
        cout << "YES" << endl;
    }
    return 0;
}