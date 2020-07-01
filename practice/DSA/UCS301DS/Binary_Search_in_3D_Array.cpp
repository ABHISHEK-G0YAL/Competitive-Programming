// https://www.codechef.com/UCSD2020/problems/DSLA4

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main() {
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    vvvi a(x, vvi(y, vi(z)));
    for(auto &vv : a)
        for(auto &v : vv)
            for(int &i : v)
                cin >> i;
    int beg = 0, end = x - 1, mid, d1 = -1, d2 = -1, d3 = -1, count = 0;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if(d1 == -1) {
            if(a.at(mid).front().front() > n)
                end = mid - 1;
            else if(a.at(mid).back().back() < n)
                beg = mid + 1;
            else {
                d1 = mid, beg = 0, end = y - 1;
                cout << a.at(d1).front().front() << " " << a.at(d1).back().back() << endl;
            }
        }
        else if(d2 == -1) {
            if(a.at(d1).at(mid).front() > n)
                end = mid - 1;
            else if(a.at(d1).at(mid).back() < n)
                beg = mid + 1;
            else {
                d2 = mid, beg = 0, end = z - 1;
                cout << a.at(d1).at(d2).front() << " " << a.at(d1).at(d2).back() << endl;
            }
        }
        else {
            if(a.at(d1).at(d2).at(mid) > n)
                end = mid - 1;
            else if(a.at(d1).at(d2).at(mid) < n)
                beg = mid + 1;
            else {
                d3 = mid, beg = 0, end = -1;
                cout << d1 << " "<< d2 << " "<< d3 << endl;
            }
        }
        count += 1;
    }
    if(d3 == -1)
        cout << 0 << endl;
    cout << count << endl;
}