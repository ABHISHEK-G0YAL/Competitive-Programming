// https://leetcode.com/problems/diameter-of-binary-tree/

/*
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
    int diameter = 0;
    int heightOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight = heightOfBinaryTree(root->left);
        int rightHeight = heightOfBinaryTree(root->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfBinaryTree(root);
        return diameter;
    }
};