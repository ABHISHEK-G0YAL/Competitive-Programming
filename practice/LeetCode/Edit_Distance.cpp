// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    vector<vector<int> > mem=vector<vector<int> > (1000,vector<int> (1000,-1));
    int minDistance(string w1, string w2) {
        int l1=w1.length(),l2=w2.length();
        if(mem[l1][l2]!=-1)
            return mem[l1][l2];
        if(l1==0 || l2==0)
            mem[l1][l2]=l1?l1:l2;
        else if(w1[0]==w2[0])
            mem[l1][l2]=minDistance(w1.substr(1),w2.substr(1));
        else
            mem[l1][l2]=1+min( { minDistance(w1.substr(1),w2.substr(1)),
                          minDistance(w1.substr(1),w2),
                         minDistance(w1,w2.substr(1)) } );
        return mem[l1][l2];
    }
};
