// https://www.hackerrank.com/contests/university-codesprint-5/challenges/array-triplets/problem

#include <bits/stdc++.h>
using namespace std;


// Terminated due to timeout
// O(4 ^ n)
class Solution1 {
    vector<int> &a, powerset;
    long targetSum = 0;

    // O(2 ^ n)
    void allSubsets(int set = 0, int i = 0, long currentSum = 0) {
        if (i == (int) a.size()) {
            if (currentSum == targetSum && set) {
                powerset.push_back(set);
            }
            return;
        }
        allSubsets(set, i + 1, currentSum);
        allSubsets(set + (1 << i), i + 1, currentSum + a[i]);
    }

public:
    Solution1(vector<int> &a) : a(a) { }

    // O((2 ^ n) ^ 2)
    int solve() {
        for (int i : a) {
            targetSum += i;
        }
        if (targetSum % 3 != 0) {
            return 0;
        }
        targetSum /= 3;
        allSubsets();
        long triplets = 0;
        for (int i = 0; i < (int) powerset.size(); ++i) {
            for (int j = i + 1; j < (int) powerset.size(); ++j) {
                if ((powerset[i] & powerset[j]) == 0)
                    triplets += 2;
            }
        }
        return triplets;
    }
};

// O(3 ^ n)
class Solution2 {
    vector<int> &a;
    long sumA = 0, sumB = 0, sumC = 0, n;
    int countA = 0, countB = 0, countC = 0, tripletCount = 0;

public:
    Solution2(vector<int> &a) : a(a), n(a.size()) { }

    // O(3 ^ n)
    int solve(int i = 0) {
        if (i == n) {
            if (countA && countB && countC
                && sumA == sumB
                && sumB == sumC
            ) {
                ++tripletCount;
            }
            return 0;
        }
        sumA += a[i];
        ++countA;
        solve(i + 1);
        sumA -= a[i];
        --countA;

        sumB += a[i];
        ++countB;
        solve(i + 1);
        sumB -= a[i];
        --countB;

        sumC += a[i];
        ++countC;
        solve(i + 1);
        sumC -= a[i];
        --countC;

        return tripletCount;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    Solution2 solution(a);
    cout << solution.solve() << endl;
}
