// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxUntil = height, maxAfter = height;
        for (int i = 1; i < n; i++) {
            maxUntil[i] = max(maxUntil[i - 1], maxUntil[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxAfter[i] = max(maxAfter[i], maxAfter[i + 1]);
        }
        int totalWater = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            totalWater += max(0, min(maxUntil[i - 1], maxAfter[i + 1]) - height[i]);
        }
        return totalWater;
    }
};