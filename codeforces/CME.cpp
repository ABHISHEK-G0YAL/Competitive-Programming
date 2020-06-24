// http://codeforces.com/contest/1223/problem/A

#include <iostream>
using namespace std;

int main() {
    int q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        cout << (n < 4 ? 4 - n : n % 2) << endl;
    }
}