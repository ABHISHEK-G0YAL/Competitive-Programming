// https://www.hackerrank.com/challenges/mark-and-toys/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int maximumToys(vector<int> &prices, int amount) {
    sort(prices.begin(), prices.end());
    int maxToys = 0;
    while(amount >= prices[maxToys]) {
        amount -= prices[maxToys];
        maxToys += 1;
    }
    return maxToys;
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> prices(n);
    for(int &price : prices)
        cin >> price;
    cout << maximumToys(prices, amount);
}
