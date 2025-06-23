// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    // Brian Kernighan’s Algorithm
    int optimisedGetBitCount(int n) {
        int count = 0; 
        while (n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }


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
            // time complexity - O(b) where b is number of set bits
            // ans.push_back(__builtin_popcount(i));

            // time complexity - O(log n)
            // ans.push_back(getBitCount(i));

            // time complexity - O(b) where b is number of set bits
            ans.push_back(optimisedGetBitCount(i));
        }
        return ans;
    }
};