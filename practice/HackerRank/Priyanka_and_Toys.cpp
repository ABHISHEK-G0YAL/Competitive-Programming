// https://www.hackerrank.com/challenges/priyanka-and-toys/problem
// Accepted

#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int main() {
    int n, w;
    cin >> n;
    vector<int> c(MAX);
    for(int i = 0; i < n; i++) {
        cin >> w;
        c[w] += 1;
    }
    int containers = 0;
    for(int i = 0; i < MAX; i += 1) {
        if(c[i]) {
            containers += 1;
            i += 4;
        }
    }
    cout << containers << endl;
}
