// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    static bool comprator(vector<int> &point1, vector<int> &point2) {
        return point1[1] < point2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comprator);
        long currentEnd = LLONG_MIN, arrowCount = 0;
        for (auto &point : points) {
            if (point[0] > currentEnd) {
                ++arrowCount;
                currentEnd = point[1];
            }
        }
        return arrowCount;
    }
};