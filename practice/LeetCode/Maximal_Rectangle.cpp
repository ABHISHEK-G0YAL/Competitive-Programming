// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
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
    int largestRectangleAreaInHistogram(vector<int> &heights) {
        int n = heights.size();
        vector<int> i_left = lefti(heights);
        vector<int> i_right = righti(heights);
        long mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, heights[i] * (i_right[i] - i_left[i] - 1L));
        return mx;
    }
    int maximalRectangle(vector<vector<char>> &matrix){
        if(matrix.empty())
            return 0;
        vector<int>v(matrix[0].size());
        int mx=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]+=1;
            }
            mx=max(mx,largestRectangleAreaInHistogram(v));
        }
        return mx;
    }
};