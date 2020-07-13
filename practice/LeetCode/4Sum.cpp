// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        int n = a.size();
        set<vector<int> > s;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if(binary_search(a.begin() + k + 1, a.end(), target - (a[i] + a[j] + a[k])))
                        s.insert({a[i], a[j], a[k], target - (a[i] + a[j] + a[k])});
        return vector<vector<int> >(s.begin(), s.end());
    }
};