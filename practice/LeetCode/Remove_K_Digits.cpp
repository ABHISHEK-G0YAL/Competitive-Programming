// https://leetcode.com/problems/remove-k-digits/
// Accepted    20 ms

class Solution {
    string helpRemoveKdigits(string &num, int k) {
        int n = num.length();
        if(k <= 0) return num;
        if(k == n) return "";
        int start_ind = 0;
        for(int i = 0; i <= k; i++) {
            if(num[i] < num[start_ind])
                start_ind = i;
        }
        string start;
        start.push_back(num[start_ind]);
        num = num.substr(start_ind + 1);
        return start + helpRemoveKdigits(num, k - start_ind);
    }
public:
    string removeKdigits(string &num, int k) {
        string answer = helpRemoveKdigits(num, k);
        while(answer[0] == '0') answer = answer.substr(1);
        return answer.empty() ? "0" : answer;
    }
};