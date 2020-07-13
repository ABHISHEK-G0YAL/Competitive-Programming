// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode *last, *first, *second;
    void inorder(TreeNode* root) {
        if(root) {
            inorder(root->left);
            if(last) {
                if(root->val < last->val) {
                    if(first) {
                        second = root;
                    }
                    else {
                        first = last;
                        second = root;
                    }
                }
            }
            last = root;
            inorder(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        last = first = second = NULL;
        inorder(root);
        swap(first->val, second->val);
    }
};