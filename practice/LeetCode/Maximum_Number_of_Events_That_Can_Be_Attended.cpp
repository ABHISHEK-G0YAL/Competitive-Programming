// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Accepted    1108 ms

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        int maxEndDay = 0, cnt = 0;
        unordered_map<int, vector<int>> start;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &e : events) {
            start[e[0]].push_back(e[1]);
            maxEndDay = max(maxEndDay, e[1]);
        }
        for(int d = 1; d <= maxEndDay; ++d) {
            while(!pq.empty() and pq.top() < d)
                pq.pop();
            for(auto &ed : start[d])
                pq.push(ed);
            if(!pq.empty()) {
                ++cnt;
                pq.pop();
            }
        }
        return cnt;
    }
};