// https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
void decentNumber(int n) {
    int fives = 0, threes = 0;
    while(n % 3 and n > 0) {
        n -= 5;
        threes += 1;
    }
    if(n < 0)
        cout << -1 << endl;
    else {
        fives = n / 3;
        while(fives--) cout << "555";
        while(threes--) cout << "33333";
        cout << endl;
    }
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        decentNumber(n);
    }
}
