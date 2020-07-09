// https://www.hackerrank.com/challenges/lowest-triangle/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area)
{
    return (ceil(2.0*(float)area/(float)base));
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}