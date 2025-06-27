// https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int subProblem = kthGrammar(n - 1, (k + 1) / 2);

        // if k is odd, first child is ans
        // 0 -> 01, 1 -> 10, first child = subproblem, second child = !subproblem
        return k % 2 ? subProblem : !subProblem;

    }
};