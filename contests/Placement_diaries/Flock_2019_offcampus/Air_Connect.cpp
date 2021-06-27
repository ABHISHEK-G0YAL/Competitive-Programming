#include <bits/stdc++.h>
using namespace std;

class coordinate {
public:
    int x;
    int y;
};

bool isManOne(coordinate a, coordinate b) {
    return ((a.x == b.x) and (abs(a.y - b.y) == 1)) or ((a.y == b.y) and (abs(a.x - b.x) == 1));
}

double getEuclid(coordinate a, coordinate b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        coordinate temp;
        vector<vector<coordinate> > mp;
        while (n--) {
            bool toAdd = true;
            cin >> temp.x >> temp.y;
            for(auto &v : mp) {
                for(auto &c : v) {
                    if(isManOne(temp, c)) {
                        v.push_back(temp);
                        toAdd = false;
                        break;
                    }
                }
                if(!toAdd)
                    break;
            }
            if(toAdd)
                mp.push_back({temp});
            // cout << "printing map ..." << endl;
            // for(auto v : mp) {
            //     for(auto c : v)
            //         cout << c.x << " " << c.y << '\t';
            //     cout << endl;
            // }
            // cout << "finish printing map ..." << endl;
        }
        // cout << "printing map ..." << endl;
        // for(auto v : mp) {
        //     for(auto c : v)
        //         cout << c.x << " " << c.y << '\t';
        //     cout << endl;
        // }
        // cout << "finish printing map ..." << endl;
        n = mp.size();
        int address;
        double minDist, dist, cost = 0;
        for(int i = n - 1; i > 0; i--) {
            minDist = 10000000000000.0;
            for(int j = i - 1; j >= 0; j--) {
                for(auto c1 : mp[i]) {
                    for(auto c2 : mp[j]) {
                        dist = getEuclid(c1, c2);
                        if(dist < minDist) {
                            minDist = dist;
                            address = j;
                        }
                    }
                }
            }
            mp[address].insert(mp[address].end(), mp[i].begin(), mp[i].end());
            cost += minDist;
        }
        cout << fixed << setprecision(6) << cost << endl;
    }
}