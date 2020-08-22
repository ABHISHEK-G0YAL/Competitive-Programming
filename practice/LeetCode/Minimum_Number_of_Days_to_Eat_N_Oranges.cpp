// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

class Solution {
public:
    unordered_map<int, int> mp;
    int minDays(int n) {
        return mp[n] = n > 1 ? mp[n] ? mp[n] : 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3)) : n;
    }
};

// class Solution {
// public:
//     unordered_map<int, int> mp;
//     int minDays(int n) {
//         if(n <= 1)
//             return n;
//         if(mp[n] != 0)
//             return mp[n];
//         return mp[n] = 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3));
//     }
// };