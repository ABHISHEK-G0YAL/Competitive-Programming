// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "#";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserializeHelper(stringstream &ss) {
        string node;
        getline(ss, node, ',');
        if (node == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));