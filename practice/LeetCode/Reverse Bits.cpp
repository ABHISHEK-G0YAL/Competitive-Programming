// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int start = 0, end = 31;
        while (start < end) {
            bool startBit = bool(n & (1 << start));
            bool endBit = bool(n & (1 << end));
            if (startBit != endBit) {
                n = startBit ? n & ~(1 << start) : n | (1 << start);
                n = endBit ? n & ~(1 << end) : n | (1 << end);
            }
            ++start;
            --end;
        }
        return n;
    }
};