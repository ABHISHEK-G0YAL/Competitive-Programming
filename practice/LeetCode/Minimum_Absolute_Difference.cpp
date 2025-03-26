// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> pairs;
        for (int i = 1; i < arr.size(); ++i) {
            if (pairs.empty() || arr[i] - arr[i - 1] < pairs[0][1] - pairs[0][0]) {
                pairs.clear();
                pairs.push_back({ arr[i - 1], arr[i] });
            } else if (arr[i] - arr[i - 1] == pairs[0][1] - pairs[0][0]) {
                pairs.push_back({ arr[i - 1], arr[i] });
            }
        }
        return pairs;
    }
};