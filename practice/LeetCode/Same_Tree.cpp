// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are null or same exact node
        if(p == q)
            return true;

        // if one of them is NULL
        if(p == NULL || q == NULL)
            return false;

        // if both nodes have sme value
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        // if both nodes have different value
        return false;
    }
};