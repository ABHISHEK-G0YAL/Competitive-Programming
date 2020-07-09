// https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

vector<int> maximumPerimeterTriangle(vector<int> &sticks) {
    sort(sticks.rbegin(), sticks.rend());
    for(int i = 2; i < sticks.size(); i++)
        if(sticks[i] + sticks[i - 1] > sticks[i - 2])
            return {sticks[i], sticks[i - 1], sticks[i - 2]};
    return {-1};
}

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for(auto &stick : sticks)
        cin >> stick;
    for(auto &side : maximumPerimeterTriangle(sticks))
        cout << side << " ";
    cout << endl;
}
