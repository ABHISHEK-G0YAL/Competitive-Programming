// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Accepted    24 ms

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
    TreeNode* BST(vector<int>& v, int l, int r) {
        if(l <= r) {
            int mid = (l + r) / 2;
            TreeNode* root = new TreeNode(v[mid]);
            root->left = BST(v, l, mid - 1);
            root->right = BST(v, mid + 1, r);
            // cout << root->val << endl;
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
};