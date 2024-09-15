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
    long currentMax = LONG_MIN;
    bool isBST = true;

    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        if (root->val > currentMax) {
            currentMax = root->val;
        } else {
            isBST = false;
        }
        inOrder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return isBST;
    }
};