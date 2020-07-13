// https://leetcode.com/problems/longest-univalue-path/

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
    int longestUnivaluePath(TreeNode* root, int key = -1) {
        if(root == NULL) return 0;
        int inc = 0, exc = 0;
        if(key == -1) {
            inc = longestUnivaluePath(root->left, root->val) + longestUnivaluePath(root->right, root->val);
            exc = max(longestUnivaluePath(root->left, key), longestUnivaluePath(root->right, key));
        } else if(root->val == key)
            inc = 1 + max(longestUnivaluePath(root->left, key), longestUnivaluePath(root->right, key));
        return max(inc, exc);
    }
};
