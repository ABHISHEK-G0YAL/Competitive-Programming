// https://leetcode.com/problems/meeting-rooms-ii/
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

         // can use minHeap to reduce TC
        vector<Interval> ongoingMeetings;

        for (auto &currentMeeting : intervals) {
            int newRoomRequired = true;
            for (auto &roomMeeting : ongoingMeetings) {
                if (roomMeeting.end <= currentMeeting.start) {
                    roomMeeting = currentMeeting;
                    newRoomRequired = false;
                    break;
                }
            }
            if (newRoomRequired) {
                ongoingMeetings.push_back(currentMeeting);
            }
        }
        return ongoingMeetings.size();
    }
};