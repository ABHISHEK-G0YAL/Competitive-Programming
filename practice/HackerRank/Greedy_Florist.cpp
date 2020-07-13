// https://www.hackerrank.com/challenges/greedy-florist/problem

#include <bits/stdc++.h>
using namespace std;

int getMinimumCost(int k, vector<int> c) {
    sort(c.rbegin(), c.rend());
    int minCost = 0, currPurchase = 1, friends = k;
    for(int &i : c) {
        if(!friends) {
            friends = k;
            currPurchase += 1;
        }
        minCost += i * currPurchase;
        friends -= 1;
    }
    return minCost;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for(auto &i : c)
        cin >> i;
    cout << getMinimumCost(k, c) << endl;
}
