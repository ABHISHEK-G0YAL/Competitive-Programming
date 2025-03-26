// https://www.hackerrank.com/challenges/the-prime-game/problem

#include <bits/stdc++.h>
using namespace std;

// vector<int> primeMoves = { 2, 3, 5, 7, 11, 13 };
vector<int> grundyCycle = {0, 0, 1, 1, 2, 2, 3, 3, 4};

int computeGrundy(long long n) {
    return grundyCycle[n % 9];  // Use precomputed cycle
}

int main() {
    int T, K;
    cin >> T;
    long balls;
    while (T--) {
        cin >> K;
        int xorSum = 0;
        for (int i = 0; i < K; i++) {
            cin >> balls;
            xorSum ^= computeGrundy(balls);
        }
        if (xorSum == 0)
            cout << "Sandy\n";
        else
            cout << "Manasa\n";
    }
    return 0;
}