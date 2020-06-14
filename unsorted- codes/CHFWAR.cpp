#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll min_shield(list<ll> left, list<ll> right) {
    // cout << left.size() << " " << right.size() << endl;
    if(left.empty() && right.size() == 1) 
        return 0;
    ll shield_pt = 0;
    for(auto itr = left.begin(); itr != left.end(); itr++) {
        auto next = itr;
        ++next;
        if(next != left.end())
            left.erase(next);
        else
            shield_pt += *itr;
    }
    for(auto itr = right.begin(); itr != right.end(); itr++) {
        auto next = itr;
        ++next;
        if(next != right.end())
            right.erase(next);
        else if(!left.empty())
            left.pop_front();
        else if(right.size() != 1)
            shield_pt += *itr;
        else break;
    } return shield_pt + min_shield(left, right);
}

int main() {
    int t, n, f;
    cin >> t;
    while(t--) {
        cin >> n;
        ll a[n - 1];
        for(int i = 0; i < n - 1; i++)
            cin >> a[i];
        cin >> f;
        ll min_sh = INT64_MAX;
        ll shield = INT64_MAX;
        int pos = -1;
        for(int i = 0; i < n - 1; i++) {
            int next_i = (i + 1) % (n - 1);
            if(a[next_i] < f) {
                if(next_i == 0) {
                    list<ll> left;
                    list<ll> right(a, a + n -1);
                    shield = min_shield(left, right);
                    if(shield < min_sh) {
                        min_sh = shield;
                        pos = next_i + 1;
                    } continue;
                }
                list<ll> left(a, a + i + 1);
                list<ll> right(a + i + 1, a + n - 1);
                shield = min_shield(left, right);
                if(shield < min_sh) {
                    min_sh = shield;
                    pos = next_i + 1;
                }
            }
        } 
        if(min_sh == INT64_MAX)
            cout << "impossible" << endl;
        else {
            cout << "possible" << endl;
            cout << pos << " " << min_sh + f << endl;
        }
    }
}