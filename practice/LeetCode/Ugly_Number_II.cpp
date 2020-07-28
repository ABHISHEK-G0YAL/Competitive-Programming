// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt[3] = {};
        vector<int> v = {1};
        while(v.size() < n){
            int mi = min({v[cnt[0]] * 2, v[cnt[1]] * 3, v[cnt[2]] * 5});
            if(mi == v[cnt[0]]*2)
                ++cnt[0];
            if(mi == v[cnt[1]]*3) 
                ++cnt[1];
            if(mi == v[cnt[2]]*5)
                ++cnt[2];
            v.push_back(mi);
        }
        return v.back();
    }
};