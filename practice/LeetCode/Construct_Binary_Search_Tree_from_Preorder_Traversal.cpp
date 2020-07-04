// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Accepted    8 ms

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
    TreeNode* bstFromPreorder(vector<int>& preorder, int i = 0, int mx = INT_MAX, int mn = INT_MIN) {
        if(i == preorder.size())
            return NULL;
        if(preorder[i] < mx and preorder[i] > mn) {
            TreeNode* root = new TreeNode(preorder[i]);
            root->left = bstFromPreorder(preorder, i + 1, root->val, mn);
            root->right = bstFromPreorder(preorder, i + 1, mx, root->val);
            return root;
        }
        else {
            return bstFromPreorder(preorder, i + 1, mx, mn);
        }
    }
};