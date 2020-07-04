// https://leetcode.com/problems/number-of-digit-one/
// Accepted    0 ms

class Solution {
public:
    long countDigitOne(int n) {
        int e, d;
        long m, r = 0;
        while(n > 0) {
            e = log10(n);
            m = pow(10, e);
            d = n / m;
            r += d * e * m / 10;
            if(d > 1)
                r += m;
            else
                r += n % m + 1;
            n = n % m;
        }
        return r;
    }
};