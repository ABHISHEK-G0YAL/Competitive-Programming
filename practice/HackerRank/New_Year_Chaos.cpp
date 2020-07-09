// https://www.hackerrank.com/challenges/new-year-chaos/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        int q[n + 1];
        bool too_chaotic = false;
        for (int i = 1; i <= n; i++)
            cin >> q[i];
        int b = 0;
        for (int i = n; i > 0; i--) {
            if(q[i] == i) continue;
            else if(q[i - 1] == i) {
                b += 1;
                swap(q[i - 1], q[i]);
            } else if (q[i - 2] == i) {
                b += 2;
                swap(q[i - 2], q[i - 1]);
                swap(q[i - 1], q[i]);
            } else {
                too_chaotic = true;
                break;
            }
        } if(too_chaotic) {
            cout << "Too chaotic" << endl;
        } else {
            cout << b << endl;
        }
    } return 0;
}
