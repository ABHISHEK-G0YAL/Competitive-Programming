// https://leetcode.com/problems/implement-strstr/
// Accepted    4 ms

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};