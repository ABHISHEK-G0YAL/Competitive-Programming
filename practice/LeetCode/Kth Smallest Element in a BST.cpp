// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }
        int smallest = kthSmallest(root->left, k);
        if (smallest != -1) {
            return smallest;
        }
        ++count;
        if (count == k) {
            return root->val;
        }
        return kthSmallest(root->right, k);
    }
};