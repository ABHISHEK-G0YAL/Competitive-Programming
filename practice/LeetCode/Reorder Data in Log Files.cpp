// https://leetcode.com/problems/reorder-data-in-log-files/

class Solution {
public:
    static bool isLetter(char x) {
        return 'a' <= x && x <= 'z';
    }
    static bool isDigit(char x) {
        return '0' <= x && x <= '9';
    }
    static bool compare(string s1, string s2) {
        cout << s1 << ", " << s2 << endl;
        int i = 0; 
        while(s1[i++] != ' ');
        string tag1 = s1.substr(0, i);
        s1 = s1.substr(i);
        i = 0;
        while(s2[i++] != ' ');
        string tag2 = s2.substr(0, i);
        s2 = s2.substr(i);
        cout << s1 << ", " << s2 << endl;
        if(isLetter(s1[0]) && isLetter(s2[0])) {
            if(s1 < s2) return true;
            else if(s2 < s1) return false;
            else return tag1 < tag2;
        }
        else if(isLetter(s1[0]) && isDigit(s2[0]))
            return true;
        else if(isDigit(s1[0]) && isLetter(s2[0]))
            return false;
        else
            return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), Solution::compare);
        cout << "here" << endl;
        return logs;
    }
};