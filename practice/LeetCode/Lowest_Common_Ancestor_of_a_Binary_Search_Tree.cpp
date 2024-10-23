// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* P_FOUND = new TreeNode();
    TreeNode* Q_FOUND = new TreeNode();
public:
    // Optimised using BST properties | 18 ms Beats 91.04% O(Log N)
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        // If both nodes are smaller than root, LCA must be in the left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor3(root->left, p, q);
        }
        
        // If both nodes are larger than root, LCA must be in the right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor3(root->right, p, q);
        }
        
        // If p and q are on opposite sides of root, or one of them is equal to root
        return root;
    }

    // 21 ms Beats 73.08% O(N)
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* leftLca = lowestCommonAncestor2(root->left, p, q);
        TreeNode* rightLca = lowestCommonAncestor2(root->right, p, q);
        if (leftLca && rightLca) {
            return root;
        }
        return leftLca ? leftLca : rightLca;
    }

    // 23 ms Beats 56.76% O(N)
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        TreeNode *leftLca, *rightLca;
        leftLca = lowestCommonAncestor1(root->left, p, q);
        if (leftLca != NULL && leftLca != P_FOUND && leftLca != Q_FOUND) {
            return leftLca;
        }
        rightLca = lowestCommonAncestor1(root->right, p, q);
        if (rightLca != NULL && rightLca != P_FOUND && rightLca != Q_FOUND) {
            return rightLca;
        }
        if (rightLca == P_FOUND && leftLca == Q_FOUND
        || rightLca == Q_FOUND && leftLca == P_FOUND
        || (rightLca == Q_FOUND || leftLca == Q_FOUND) && root == p
        || (rightLca == P_FOUND || leftLca == P_FOUND) && root == q) {
            return root;
        } else if (root == p || rightLca == P_FOUND || leftLca == P_FOUND) {
            return P_FOUND;
        } else if (root == q || rightLca == Q_FOUND || leftLca == Q_FOUND) {
            return Q_FOUND;
        } else {
            return NULL;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // All solutions assume that both p and q are in the tree
    
        // return lowestCommonAncestor1(root, p, q);
        // return lowestCommonAncestor2(root, p, q);
        return lowestCommonAncestor3(root, p, q);
    }
};