// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    bool isOverlap(vector<int> &interval1, vector<int> &interval2) {
        return interval1[0] < interval2[1] && interval2[0] < interval1[1];
    }

    // Greedy
    vector<int> &getEndsEarlier(vector<int> &interval1, vector<int> &interval2) {
        return interval1[1] < interval2[1] ? interval1 : interval2;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> &currentInterval = intervals[0];
        int eraseCount = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlap(currentInterval, intervals[i])) {
                ++eraseCount;
                currentInterval = getEndsEarlier(currentInterval, intervals[i]);
            } else {
                currentInterval = intervals[i];
            }
        }
        return eraseCount;
    }
};