// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Accepted    24 ms

class Solution {
public:
    long max(long a, long b) {
        return a > b ? a : b;
    }
    vector<int> lefti(vector<int> &a) {
        int n = a.size();
        vector<int> v(n, -1);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++) {
            if(a[s.top()] < a[i])
                v[i] = s.top();
            else {
                while(!s.empty() and a[s.top()] >= a[i])
                    s.pop();
                if(!s.empty())
                    v[i] = s.top();
            }
            s.push(i);
        }
        return v;
    }
    vector<int> righti(vector<int> &a) {
        int n = a.size();
        vector<int> v(n, n);
        stack<int> s;
        s.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            if(a[s.top()] < a[i])
                v[i] = s.top();
            else {
                while(!s.empty() and a[s.top()] >= a[i])
                    s.pop();
                if(!s.empty())
                    v[i] = s.top();
            }
            s.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> i_left = lefti(heights);
        vector<int> i_right = righti(heights);
        long mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, heights[i] * (i_right[i] - i_left[i] - 1L));
        return mx;
    }
};