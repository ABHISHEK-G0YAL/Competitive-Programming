// https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
    int mi = INT_MAX, ma = INT_MIN;
    for(auto &r : A) {
        mi = min(mi, r.front());
        ma = max(ma, r.back());
    }
    int half = (A.size() * A[0].size() + 1) / 2, mid, place;
    while(mi < ma) {
        place = 0;
        mid = (mi + ma) / 2;
        for(auto &r : A) 
            place += upper_bound(r.begin(), r.end(), mid) - r.begin(); 
        if (place < half) 
            mi = mid + 1; 
        else
            ma = mid;
    }
    return mi;
}