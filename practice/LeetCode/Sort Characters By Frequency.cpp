// https://leetcode.com/problems/sort-characters-by-frequency/

class SolutionNLogN {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            ++mp[c];
        }
        auto cmp = [&](char a, char b) {
            if (mp[a] == mp[b]) {
                return a < b;
            }
            return mp[a] > mp[b];
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            ++mp[c];
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto &p1, auto p2) {
            return p1.second > p2.second;
        });
        string ans;
        ans.reserve(s.length());
        for (auto [ch, f]: v) {
            ans.append(f, ch);
        }
        return ans;
    }
};