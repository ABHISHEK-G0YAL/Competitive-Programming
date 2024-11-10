// https://www.lintcode.com/problem/919/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool comprator(Interval &x, Interval &y) {
    return x.start < y.start;
}

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), comprator);
        priority_queue<int, vector<int>, greater<int>> ongoingMeetings;
        for (auto &currentMeeting : intervals) {
            if (!ongoingMeetings.empty() && ongoingMeetings.top() <= currentMeeting.start) {
                ongoingMeetings.pop();
            }
            ongoingMeetings.push(currentMeeting.end);
        }
        return ongoingMeetings.size();
    }
};