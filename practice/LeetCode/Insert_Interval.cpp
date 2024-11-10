// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    bool isOverlap(vector<int>& interval1, vector<int>& interval2) {
        int L1 = interval1[0], R1 = interval1[1];
        int L2 = interval2[0], R2 = interval2[1];
        return L1 < L2 ? R1 >= L2 : R2 >= L1;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // auto i = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        bool addedNewInterval = false;
        vector<vector<int>> newIntervals;
        int l = -1, r = -1;
        for (auto &interval : intervals) {
            if (isOverlap(interval, newInterval)) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            } else {
                if (interval[0] > newInterval[1] && !addedNewInterval) {
                    newIntervals.push_back(newInterval);
                    addedNewInterval = true;
                }
                newIntervals.push_back(interval);
            }
        }
        if (!addedNewInterval) {
            newIntervals.push_back(newInterval);
            addedNewInterval = true;
        }
        return newIntervals;
    }
};
