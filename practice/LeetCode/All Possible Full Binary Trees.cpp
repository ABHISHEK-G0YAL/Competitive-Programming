// https://leetcode.com/problems/all-possible-full-binary-trees/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*> > dp;
    void merge(vector<TreeNode*> &main, vector<TreeNode*> &left, vector<TreeNode*> &right) {
        for(auto l : left) {
            for(auto r : right) {
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                main.push_back(root);
            }
        }
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        dp[1].push_back(new TreeNode(0));
        for(int n = 3; n <= N; n += 2)
            for(int i = 1; i < n; i += 2)
                merge(dp[n], dp[i], dp[n - 1 - i]);
        return dp[N];
    }
    
};