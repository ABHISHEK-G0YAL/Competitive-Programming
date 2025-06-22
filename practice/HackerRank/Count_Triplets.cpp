// https://www.hackerrank.com/challenges/count-triplets-1/problem

#include <bits/stdc++.h>
using namespace std;

long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> left, right;
    for (long &i : arr) {
        ++right[i];
    }
    long nTriplets = 0;
    for (long &mid : arr) {
        --right[mid];
        if (mid % r == 0) {
            nTriplets += (left[mid / r] * right[mid * r]);
        }
        ++left[mid];
    }
    return nTriplets;
}

int main() {
    long n, r;
    cin >> n >> r;
    vector<long> arr(n);
    for (long &i : arr) {
        cin >> i;
    }
    cout << countTriplets(arr, r) << endl;
    return 0;
}
