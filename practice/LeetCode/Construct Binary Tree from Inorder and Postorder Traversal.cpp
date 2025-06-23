// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pr) {
        if (pr < 0) {
            return NULL;
        }
        // Can use Map instead of linear search
        int rootIndex = -1;
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == postorder[pr]) {
                rootIndex = i;
                break;
            }
        }
        if (rootIndex == -1) {
            // return buildTreeHelper(inorder, postorder, il, ir, pr - 1);
            return NULL;
        }
        TreeNode *node = new TreeNode(postorder[pr]);
        node->right = buildTreeHelper(inorder, postorder, rootIndex + 1, ir, pr - 1);
        // node->left = buildTreeHelper(inorder, postorder, il, rootIndex - 1, pr - 1);
        node->left = buildTreeHelper(inorder, postorder, il, rootIndex - 1, pr - 1 - (ir - rootIndex));
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return buildTreeHelper(inorder, postorder, 0, n - 1, n - 1);
    }
};