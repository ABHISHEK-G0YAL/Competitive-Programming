// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        deque<TreeNode*> parent;
        deque<TreeNode*> child;
        parent.push_back(root);
        int maxWidth = 0;
        while(!parent.empty()) {
            maxWidth = max(maxWidth, int(parent.size()));
            for(auto &node : parent) {
                // cout << node << " ";
                child.push_back(node ? node->left : NULL);
                child.push_back(node ? node->right : NULL);
            }
            // cout << endl;
            parent = child;
            child.clear();
            while(!parent.empty() and !parent.back())
                parent.pop_back();
            while(!parent.empty() and !parent.front())
                parent.pop_front();
        }
        return maxWidth;
    }
};