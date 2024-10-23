// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    // TC - O(n)
    int maxRootLeafSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxRootLeafSum(root->left);
        int right = maxRootLeafSum(root->right);
        return max(root->val + max(left, right), 0);
    }

    // TC - O(n ^ 2)
    int maxPathSum1(TreeNode* root) {
        if (!root) {
            return INT_MIN;
        }
        int leftSum = maxPathSum(root->left);
        int rightSum = maxPathSum(root->right);
        int sum = maxRootLeafSum(root->left) + maxRootLeafSum(root->right) + root->val;
        return max({leftSum, rightSum, sum});
    }

    // TC - O(n)
    int maxRootLeafSum(TreeNode* root, int &maxPathSum) {
        if (!root) {
            return 0;
        }
        int left = maxRootLeafSum(root->left, maxPathSum);
        int right = maxRootLeafSum(root->right, maxPathSum);
        maxPathSum = max(maxPathSum, left + right + root->val);
        return max(root->val + max(left, right), 0);
    }

    // TC - O(n)
    int maxPathSum2(TreeNode* root) {
        int maxPathSum = INT_MIN;
        maxRootLeafSum(root, maxPathSum);
        return maxPathSum;
    }

    int maxPathSum(TreeNode* root) {
        // 173 ms Beats 5.62%
        // return maxPathSum1(root);

        // 0 ms Beats 100.00%
        return maxPathSum2(root);
    }
};