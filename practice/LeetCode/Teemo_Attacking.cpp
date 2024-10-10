// https://leetcode.com/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int lastAttack = INT_MIN, poisonedTime = 0;
        for (int time : timeSeries) {
            if (time > lastAttack) {
                poisonedTime += duration;
            } else {
                poisonedTime += max(0, time + duration - 1 - lastAttack);
            }
            lastAttack = time + duration - 1;
        }
        return poisonedTime;
    }
};