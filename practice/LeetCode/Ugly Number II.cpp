// https://leetcode.com/problems/ugly-number-ii/

int v[1700];
class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt[3] = {};
        v[0] = 1;
        for(int i = 1; i < n; ++i) {
            int mi = min({v[cnt[0]] * 2, v[cnt[1]] * 3, v[cnt[2]] * 5});
            if(mi == v[cnt[0]]*2)
                ++cnt[0];
            if(mi == v[cnt[1]]*3) 
                ++cnt[1];
            if(mi == v[cnt[2]]*5)
                ++cnt[2];
            v[i] = mi;
        }
        return v[n - 1];
    }
};