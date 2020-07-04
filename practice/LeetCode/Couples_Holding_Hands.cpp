// https://leetcode.com/problems/couples-holding-hands/
// Wrong Answer    N/A

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), count = 0;
        set<pair<int, int> > input;
        for(int i = 0; i < n; i += 2)
            input.insert({row[i], row[i + 1]});
        for(int i = 0; i < n; i += 2) {
            if(input.find({i, i + 1}) == input.end() and input.find({i + 1, i}) == input.end())
                count += 1;
        }
        if(count == 0)
            return 0;
        else 
            return count - 1;
    }
};