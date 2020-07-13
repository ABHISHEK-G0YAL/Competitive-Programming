// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        vector<pair<int, int> > mm(n);
        int m1 = 0, m2 = 0;
        for(int i = 0; i < n; i++) {
            m1 = max(m1, height[i]);
            m2 = max(m2, height[n - 1 - i]);
            mm[i].first = m1;
            mm[n - 1 - i].second = m2;
        } for(int i = 0; i < n; i++) {
            int drops = min(mm[i].first, mm[i].second) - height[i];
            water += drops > 0 ? drops : 0;
        } return water;
    }
};