// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prevAns = countAndSay(n - 1);
        string newAns = "";
        char lastCh = prevAns[0];
        int count = 0;
        for(auto ch : prevAns) {
            if(ch == lastCh) count++;
            else {
                newAns += (to_string(count) + lastCh);
                count = 1;
                lastCh = ch;
            }
        } newAns += (to_string(count) + lastCh);
        return newAns;
    }
};