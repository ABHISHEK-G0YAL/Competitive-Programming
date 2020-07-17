// https://leetcode.com/problems/circular-array-loop/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int i, j, cnt, n = nums.size();
        for(i = 0; i < n; i++) {
            j = i, cnt = 0;
            while(nums[j] > 0 and cnt < n) {
                j = (j + nums[j]) % n;
                cnt += 1;
                if(i == j) {
                    if(cnt > 1)
                        return true;
                    else
                        break;
                }
            }
            j = i, cnt = 0;
            while(nums[j] < 0 and cnt < n) {
                j = (j + nums[j] + (100 * n)) % n;
                cnt += 1;
                if(i == j) {
                    if(cnt > 1)
                        return true;
                    else
                        break;
                }
            }
        }
        return false;
    }
};