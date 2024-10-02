// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> combination;
    // adding & here greatly reduces runtime (by 250x)
    // Returning a vector by reference instead of by value significantly reduces runtime by avoiding costly copies.
    vector<vector<int>>& combinationSum(vector<int>& candidates, int target, int i = 0) {
        if (target == 0) {
            combinations.push_back(combination);
            return combinations;
        }
        if (i == candidates.size()) {
            return combinations;
        }
        combinationSum(candidates, target, i + 1);
        if (candidates[i] <= target) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i);
            combination.pop_back();
        }
        return combinations;
    }
};