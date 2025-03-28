# Air Connect

There is an infinite grid. You are given N points on it. 2 points are said to be connected if the manhattan distance between them is equal to 1. If 2 points aren't connected you can connect by air-pathways, i.e. you can take a flight from 1 point to the other. The cost of an air-pathway is the euclidean distance between the 2 points. 

If there are 3 points A, B, C. Let's say point A & B are connected(by land or by air), B & C are connected(by land or by air), then by transitivity, A & C are also connected. You have to connect all points in the same time ***minimizing the total cost.***

### Input:

- First line will contain T, number of testcases. Then the testcases follow.
- First line of each testcase contains N.
- Then N lines follow where i'th line contains the x and y coordinates of the i'th point. 

### Output:
For each testcase, output in a single line the minimum cost with 6 exactly 6 decimal places.

### Constraints:
- 1 <= T <= 10
- 1 <= N <= 500
- 1 <= x <= 10^6 
- 1 <= y <= 10^6

### Example:
#### Input
```
1
3
1 1
2 2
3 2
```
#### Output
```
1.414214
```

### Solution
### C++
```cpp
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
        }
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
```