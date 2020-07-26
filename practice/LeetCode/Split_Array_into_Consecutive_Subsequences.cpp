// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int> > > min_heap_mp;
        for(int i : nums) {
            if(min_heap_mp.find(i - 1) == min_heap_mp.end())
                min_heap_mp[i].push(1);
            else {
                int len = min_heap_mp[i - 1].top();
                min_heap_mp[i - 1].pop();
                if(min_heap_mp[i - 1].empty())
                    min_heap_mp.erase(i - 1);
                min_heap_mp[i].push(len + 1);
            }
        }
        for(auto &pq : min_heap_mp)
            if(pq.second.top() < 3)
                return false;
        return true;
    }
};