// https://leetcode.com/problems/koko-eating-bananas/

#include <ranges>

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int speed) {
        int time = 0;
        for (int pile : piles) {
            time += ceil(double(pile) / speed);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_speed = *max_element(piles.begin(), piles.end());

        auto speeds = views::iota(1, max_speed + 1);

        auto it = ranges::lower_bound(speeds, true, {}, [&](int speed) {
            return canEat(piles, h, speed);
        });

        return *it;
    }
};