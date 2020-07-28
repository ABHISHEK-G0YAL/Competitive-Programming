// https://leetcode.com/problems/ugly-number-iii/

typedef long long int lli;
class Solution {
public:
    lli lcm(lli a, lli b) {
        return a * b / __gcd(a, b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {  
        int l = 1, r = 2e9, m, cnt;
        while(l <= r) {
            m = l + (r - l) / 2;
            cnt = (m / a) + (m / b) + (m / c) - (m / lcm(a, b)) - (m / lcm(b, c)) - (m / lcm(a, c)) + (m / lcm(c, lcm(a, b)));
            if(cnt < n)
                l = m + 1;
            else
                r = m - 1;
        }
        return r + 1;
    }
};