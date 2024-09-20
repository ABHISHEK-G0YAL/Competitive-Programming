// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastTrue = nums.size() - 1;
        for(int i = lastTrue - 1; i >= 0; i--) {
            if (i + nums[i] >= lastTrue) {
                lastTrue = i;
            }
        }
        return lastTrue == 0;
    }
};