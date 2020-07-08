// https://leetcode.com/problems/maximal-rectangle/
// Accepted    116 ms

class Solution {
public:
    vector<int>nsr(vector<int>heights){
        vector<int>right;
        stack<pair<int,int>>s;
        int pseudoindex=heights.size();
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            if(s.size()==0)
                right.push_back(pseudoindex);
            else if(s.size()>0 && s.top().first<heights[i])
                right.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]) {
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.size()==0)
                    right.push_back(pseudoindex);
                else
                    right.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    vector<int>nsl(vector<int> heights) {
        vector<int>l;
        stack<pair<int,int>>s;
        int pseudoindex=-1;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(s.size()==0)
                l.push_back(pseudoindex);
            else if(s.size()>0 && s.top().first<heights[i])
                l.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.size()==0)
                    l.push_back(pseudoindex);
                else
                    l.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        return l;
    }
    int mah(vector<int> heights) {
        if(heights.size()==0)
            return 0;
        vector<int>left=nsl(heights);
        vector<int>right=nsr(heights);
        int n=heights.size();
        vector<int>area;
        for(int i=0;i<n;i++)
            area.push_back(heights[i]*(right[i]-left[i]-1));
        int maxi=INT_MIN;
        for(int i=0;i<area.size();i++)
            if(area[i]>maxi)
                maxi=area[i];
        return maxi; 
    }
    int maximalRectangle(vector<vector<char>>& matrix){
        if(matrix.size()==0)
            return 0;
        vector<int>v(matrix[0].size());
        int mx=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==0)
                    v[j]=matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='0')
                        v[j]=0;
                    else
                        v[j]=v[j]+1;
                }
            }
            mx=max(mx,mah(v));
        }
        return mx;
    }
};