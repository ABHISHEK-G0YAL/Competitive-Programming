// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> combination;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int i = 0) {
        if (target == 0) {
            combinations.push_back(combination);
            return combinations;
        }
        if (i == candidates.size()) {
            return combinations;
        }
        int count = 0;
        combinationSum(candidates, target, i + 1);
        while(target - candidates[i] >= 0) {
            combination.push_back(candidates[i]);
            target -= candidates[i];
            ++count;
            combinationSum(candidates, target, i + 1);
        }
        combination.resize(combination.size() - count);
        return combinations;
    }
};