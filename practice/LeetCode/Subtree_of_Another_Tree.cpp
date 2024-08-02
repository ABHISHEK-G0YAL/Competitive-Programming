// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool isEqual(TreeNode *root1, TreeNode *root2) {
        if (root1 == root2)
            return true;
        if (!root1 || !root2)
            return false;
        return root1->val == root2->val
            && isEqual(root1->left, root2->left)
            && isEqual(root1->right, root2->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == subRoot)
            return true;
        if (!root)
            return false;
        return isEqual(root, subRoot)
            || isSubtree(root->left, subRoot)
            || isSubtree(root->right, subRoot);
        
    }
};