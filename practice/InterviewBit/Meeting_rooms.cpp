// https://www.interviewbit.com/problems/meeting-rooms/

int Solution::solve(vector<vector<int> > &intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> ongoingMeetings;
    for (auto &currentMeeting : intervals) {
        if (!ongoingMeetings.empty() && ongoingMeetings.top() <= currentMeeting[0]) {
            ongoingMeetings.pop();
        }
        ongoingMeetings.push(currentMeeting[1]);
    }
    return ongoingMeetings.size();
}