// https://leetcode.com/problems/longest-increasing-subsequence/
// Accepted    91 ms

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int memo[][] = new int[nums.length + 2][nums.length];
        for (int[] l : memo) {
            Arrays.fill(l, -1);
        }
        return lengthofLIS(nums, 0, 0, memo);
    }
    public int lengthofLIS(int[] nums, int previndex, int curpos, int[][] memo) {
        if (curpos == nums.length) {
            return 0;
        }
        if (memo[previndex][curpos] >= 0) {
            return memo[previndex][curpos];
        }
        int taken = 0;
        if (previndex <= 0 || nums[curpos] > nums[previndex - 1]) {
            taken = 1 + lengthofLIS(nums, curpos + 1, curpos + 1, memo);
        }

        int nottaken = lengthofLIS(nums, previndex, curpos + 1, memo);
        memo[previndex][curpos] = Math.max(taken, nottaken);
        return memo[previndex][curpos];
    }
}