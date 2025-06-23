// https://leetcode.com/problems/points-that-intersect-with-cars/

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, last = 0;
        for (auto& num : nums) {
            num[0] = max(last, num[0]);
            sum += max(num[1] - num[0] + 1, 0);
            last = max(last, num[1] + 1);
        }
        return sum;
    }
};