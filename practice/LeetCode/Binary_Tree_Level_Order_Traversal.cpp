// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> levels(1);
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr) {
                levels.back().push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            } else {
                if (!q.empty()) {
                    levels.push_back({});
                    q.push(NULL);
                }
            }
        }
        return levels;
    }
};