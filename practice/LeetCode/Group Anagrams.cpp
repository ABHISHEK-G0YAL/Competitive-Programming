// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> groupedAnagrams;
        for (auto &[key, group] : mp) {
            groupedAnagrams.push_back(group);
        }
        return groupedAnagrams;
    }
};