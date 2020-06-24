// http://codeforces.com/contest/349/problem/B

#include <iostream>
using namespace std;

int main() {
    int amt, cost[10], min = INT_MAX, min_d = 0;
    cin >> amt;
    for(int x = 1; x < 10; x++) {
        cin >> cost[x];
        if(cost[x] <= min) {
            min = cost[x];
            min_d = x;
        }
    } int digits = amt / min;
    string num(digits, min_d + '0');
    for(int x = 1; x < 10; x++)
        cost[x] -= min;
    amt %= min;
    for(int i = 0; i < digits; i++) {
        for(int x = 9; x >= min_d; x--) {
            if(cost[x] <= amt) {
                num[i] = x + '0';
                amt -= cost[x];
                break;
            } 
        }
    } cout << (num.empty()?"-1":num) << endl;
}