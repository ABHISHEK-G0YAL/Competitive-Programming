// https://leetcode.com/problems/number-of-squareful-arrays/
// Accepted    0 ms

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