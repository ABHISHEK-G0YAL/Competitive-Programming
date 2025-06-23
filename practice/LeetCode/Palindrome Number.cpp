// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    long reverse(int x) {
        long n = 0;
        while (x) {
            n = (n * 10) + (x % 10);
            x = x / 10;
        }
        return n;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        return x == reverse(x);
    }
};