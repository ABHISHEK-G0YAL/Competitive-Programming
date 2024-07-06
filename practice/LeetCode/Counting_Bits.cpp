// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    int getBitCount(int n) {
        // 1 << 31 is neagtive and causes problems
        // Use unsigned int or use 1 << 30
        int mask = 1 << 30, count = 0;
        while (mask) {
            if (n & mask) {
                ++count;
            }
            mask = mask >> 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(getBitCount(i));
        }
        return ans;
    }
};