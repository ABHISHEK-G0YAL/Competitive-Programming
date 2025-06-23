// https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(K == 1) return 0;
        bool sa = kthGrammar(N, (K + 1) / 2);
        if(K & 1) return sa;
        else return !sa;
    }
};