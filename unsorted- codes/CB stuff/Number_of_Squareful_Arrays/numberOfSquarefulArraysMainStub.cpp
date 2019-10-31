#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checksquareful(int x, int y) {
        double sq = sqrt(x + y);
        return (sq - floor(sq)) == 0;
    }
    int numSquarefulPerms(vector<int>& A, int i = 0, int last = -1) {
        if(i == 0) sort(A.begin(), A.end());
        if(i == A.size()) return 1;
        int prev = -1, count = 0;
        for(int j = 0; j < A.size(); j++) {
            if(A[j] != prev and (last == -1 or A[j] != -1 and checksquareful(last, A[j]))) {
                prev = A[j];
                A[j] = -1;
                count += numSquarefulPerms(A, i + 1, prev);
                A[j] = prev;
            }
        } return count;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        Solution s;
        cout << s.numSquarefulPerms(A) << endl;
    } return 0;
}