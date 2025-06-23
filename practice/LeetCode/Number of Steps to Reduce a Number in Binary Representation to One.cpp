// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        bool carry = false;
        while(s.length() > 1) {
            char c = s.back();
            if(carry) {
                if(c == '0')
                    steps += 2;
                else
                    ++steps;
            }
            else {
                if(c == '0')
                    ++steps;
                else {
                    carry = true;
                    steps += 2;
                }
            }
            s.pop_back();
        }
        return steps + carry;
    }
};