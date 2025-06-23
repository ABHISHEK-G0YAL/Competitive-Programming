https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> mp;
        for(char c : S)
            ++mp[c];
        priority_queue<pair<int, char>> pq;
        for(auto &p : mp)
            pq.push({p.second, p.first});
        string s = "";
        pair<int, char> c1, c2;
        while(!pq.empty()) {
            cout << pq.size() << endl;
            c1 = pq.top();
            pq.pop();
            if(!pq.empty()) {
                c2 = pq.top();
                pq.pop();
                for(int i = 0; i < c2.first; i++)
                    s = s + c1.second + c2.second;
                if(c1.first - c2.first != 0)
                    pq.push({c1.first - c2.first, c1.second});
            }
            else if(c1.first == 1 and c1.second != s.back())
                s = s + c1.second;
            else
                return "";
        }
        return s;
    }
};