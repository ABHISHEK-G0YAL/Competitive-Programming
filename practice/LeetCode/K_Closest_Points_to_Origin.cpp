// https://leetcode.com/problems/k-closest-points-to-origin/

//compare dist b/w 2 points
class Solution {
static bool cmp(vector<int> &p1, vector<int> &p2) {
    return sqrt(pow(p1[0], 2) + pow(p1[1], 2)) < sqrt(pow(p2[0], 2) + pow(p2[1], 2));
}
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int N = points.size();
        make_heap(points.begin(), points.begin() + K, cmp);
        for(int i = K; i < N; i++) {
            points[K] = points[i];
            push_heap(points.begin(), points.begin() + K + 1, cmp);
            pop_heap(points.begin(), points.begin() + K + 1, cmp);
        }
        points.erase(points.begin() + K, points.end());
        return points;
    }
};