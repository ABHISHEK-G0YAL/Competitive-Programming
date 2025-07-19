// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string &word : words) {
            ++mp[word];
        }

        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            // min-heap: if freq equal, word with lower lex order is "greater" (higher priority)
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> minHeap(cmp);
        for (auto &[word, freq] : mp) {
            minHeap.push({freq, word});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<string> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};