// https://www.hackerrank.com/contests/university-codesprint-4/challenges/cubes-and-cylinders/problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cubes(n), cylinders(m);
    for (auto &[s, k] : cubes) {
        cin >> s;
    }
    for (auto &[s, k] : cubes) {
        cin >> k;
    }
    for (auto &[r, c] : cylinders) {
        cin >> r;
    }
    for (auto &[r, c] : cylinders) {
        cin >> c;
    }
    sort(cubes.begin(), cubes.end());
    sort(cylinders.begin(), cylinders.end());
    int totalStoredPackages = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        auto &[cubeEdge, numberCubes] = cubes[i];
        auto &[cylinderRadius, maxPackages] = cylinders[j];
        if (1.4142 * cubeEdge < 2 * cylinderRadius) {
            int storedPackages = min(numberCubes, maxPackages);
            totalStoredPackages += storedPackages;
            numberCubes -= storedPackages;
            maxPackages -= storedPackages;
            if (numberCubes == 0) {
                ++i;
            }
            if (maxPackages == 0) {
                ++j;
            }
        } else {
            ++j;
        }
    }
    cout << totalStoredPackages;
}