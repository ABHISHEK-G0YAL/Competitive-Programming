// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long upper = LLONG_MAX, long lower = LLONG_MIN) {
        if(!root) {
            return true;
        }
        if (root->val >= upper || root->val <= lower) {
            return false;
        }
        return isValidBST(root->left, root->val, lower) && isValidBST(root->right, upper, root->val);
    }
};