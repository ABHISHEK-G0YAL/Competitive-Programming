// https://leetcode.com/problems/4sum/
// Time Limit Exceeded    O(n^4)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &a, int target) {
        int n = a.size();
        set<vector<int> > s;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    for (int l = k+1; l < n; l++)
                        if (a[i] + a[j] + a[k] + a[l] == target)
                                s.insert({a[i], a[j], a[k], a[l]});
        return vector<vector<int> >(s.begin(), s.end());
    }
};